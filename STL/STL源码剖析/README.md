#STL源码剖析笔记
STL的通用规范：
- 对于begin()和end()的包含标准是“前闭后开”。
- 对于插入操作的规范是，将新节点插入所指节点的前方。

##序列式容器(sequence containers)
- vector：动态数组，线性连续空间，保持其capacity总是比size大，当超过容量之后，一般其capacity会以两倍速率增容。因为是线性连续空间，因此其迭代器和常用的数组指针基本一致。
- list：环状双向链表，只需要一个指针就可以表现整个链表。为了符合STL“前闭后开”的规范，在环状链表的尾端增减一个空白节点(end迭代器将指向这个节点)。
- deque：双向开口的连续线性空间，是可以在头尾两端分别做元素的插入和删除操作。deque由一段一段的定量连续空间构成，一旦需要再deque的前端或尾端添加新空间，便配置一段定量连续空间，串接在整个deque的头端或尾端。deque 的任务是在分段的定量连续空间上，维护整体连续的假象，并提供随机存取的接口(用复杂的迭代器架构，来避开“重新配置、复制、释放”的轮回)，具体实现机制是采用一块map作为中控器，map是一小块连续空间(map默认值为0时，分配的缓冲区大小为512字节)，其中每个元素都是指针，指向另一段较大的连续线性空间，称为缓冲区(缓冲区才是deque的储存空间主体)。因为front和back在容量超限时，可以随时开辟新空间，每个deque都会有两个iterator，分别是start和end(各自包含四部分：cur,fisrt,last,node)。**deque无任何元素时保有一个缓冲区，因此即使是clear清楚所有元素后，也含有一个缓冲区**。
  - deque和vector的差异：一是deque允许于常数时间内对起头端进行元素的插入或移除操作。而是deque没有所谓容量(capacity)的概念，因为它是动态以分段连续空间组合而成，随时可以增加一段新的空间并链接起来，因此deque也没有必要提供空间保留(reserve)功能。
  - deque也提供迭代器，但是其复杂度比vector大，因此为了运算效率，**应尽可能使用vector而非deque**。于是在进行排序时，可以先将deque复制到vector身上，将vector排序后，再复制回deque。
- stack：缺省情况下，STL以deque作为stack的底部结构，封闭其头端开口(适配器设计模式)，实现先进后出的数据结构，因此stack往往被称为**container adapter**，模板中描述底端容器的代码为`template<class T, class Sequence = deque<T> >`。也是因为功能已经由底层容器实现，stack的实现代码通常比较简单。stack的元素必须“先进后出”，只有顶端元素才能被取用，**stack不提供走访功能，也不提供迭代器**。
  - list也是双向容器，可以作为stack的底层容器。当使用list为底端容器时，栈的定义为`stack<int,list<int>>`。
- `queue`是一种先进先出的数据结构，限制只有最底端可以加入、最顶端可以去除。因此**queue不允许有遍历行为，没有迭代器**。使用双向开口的容器可以很方便地用适配器来实现队列功能，SGI STL缺省以deque为queue的底部结构(封闭其底端出口和顶端入口),queue的实现也因此很简单。
  - 也可以用list作为queue的底层容器，这个时候queue的定义为`queue<int,list<int>> iqueue`。
- heap并不归属于STL容器组件，bianry max heap是其他数据结构(如priority queue优先队列等)实现的基础。**binary heap就是一种complete binary tree**。
  - 因为完全二叉树没有任何节点漏洞，根据其位置规则，**可以用array来存储所有节点**(当complete binary tree中某个节点位于array的i处时，其左子节点必位于array的2i处，右子节点必位于array的2i+1处，父节点必位于"i/2"处（此时认为其根结点#0元素被保留）。因此用vector(实现完全二叉树complete binary tree)加上heap算法，就可以实现binary max heap。
  - max-heap的最大值在根结点，min-heap的最小值在根结点，根结点总是在底层array/vector的起头处。
  - 对于heap的几种操作的介绍
    - push_heap：新加入的元素一定要放在下一层作为叶结点，即填补在vector的end()处。在添加完新元素之后，为满足max-heap的条件，会执行一个所谓的percolate up(上溯)程序(将新节点与其父节点做比较，如果其键值比父节点大，父子对换位置，如此一直上溯，直至不需要对换或直到根节点为止)。
    - pop_heap：pop操作取走max-heap的最大值，即其根结点(vector的首位元素)，为满足完全二叉树的特性，割舍最下层最右边的叶结点，将其值重新安插至max-heap(以填补pop后的空洞)，执行所谓的percolate down(下溯)程序：将空间节点和**其较大子节点**“对调”，并持续下放，直至叶节点为止，将之前被割舍的元素填充给这个“已经到达叶层的空洞节点”，再对它执行一次上溯(percolate up)操作。具体地，在进行代码编写时，会将最大值(max-heap的首元素)放置到底部容器的最末（之后pop_back()取出尾值），然后重整[first,last-1)为一个合格的heap。**每次pop_heap之后，最大元素只是置放于容器的最尾端，尚未被取走，如果要取其值，还需要用底部容器的pop_back()操作。**
    - sort_heap：每次pop_heap可获得heap中键值最大的元素，并将操作范围将前缩减一个元素，整个程序执行完毕时，就有了一个递增序列。sort_heap函数接受两个迭代器，用来表现一个heap底部容器(vector)的头和具体实现算法参见下方。
    - make_heap：用来将一段现有的数据转化为一个heap，函数原型为`inline void make_heap(RandomAccessIterator first, RandomAccessIterator last)`
  - 因为heap的读取需要遵守内部特定的排列规则，因此**heap不提供遍历功能，也不提供迭代器**。(只要是限制读取规则的，一般都不提供迭代器)。
```c++
//sort heap算法
template <class RandomAccessIterator>
void sort_heap(RandomAccessIterator first,
		RandomAccessIterator last>{
	while(last- first>1)
		pop_heap(fist,last--);
}
```
- priority_queue：仍旧只允许在底端加入元素，并只从顶端取出元素，但是其中元素排列依照**权值顺序排列**，权值最高者优先出队列。**priority queue基于heap实现，也是一种container adapter**。
  - 同样地，因为priority_queue有规定好的读入读出规则，它不提供遍历功能，也**不提供迭代器**。

##关联式容器
关联式容器，观念上类似关联式数据库，每笔数据都有一个键值key和一个实值value，容器内部结构可能是RB-Tree，也可能是hash-table(取决于是否需要元素有序排列)，关联式容器无首尾（只会有最大元素，最小元素这种）。
- set：所有元素会按照元素的键值被排序，set元素的键值就是实值，实值就是键值，**不允许有两个元素相同的键值**。如果任意改变set元素值(因为set需要根据其元素值进行自动排序)，会严重破坏set组织，因此set iterators是一种constant iterators(不允许通过迭代器修改元素值)。
  - set进行元素新增/删除时，除被操作元素外，其他元素的迭代器都依然有效（因为底层是红黑树实现，树的实现仍然是靠指针相连，完全可以理解为链表）。
  - set中一般不允许有重复键，因此常采用红黑树的insert_unique方法，另外有一种multiset，允许重复键出现，采用的值插入方法是insert_equal。
- map：map的所有元素都是pair，会根据元素的键值自动被排序，pair中第一元素是key，第二元素是value。map中不允许两个pair拥有相同的键值。map的底层实现机制也是红黑树，红黑树的排列规则依靠map的key，因此不能改变map的元素键值(否则会严重破坏map的组织)，但是修改map的value是完全允许的。（另外还有一种用hash函数找元素位置然后进行元素插入的hash_set，但set自动排序，而hash_set不进行自动排序） 。

