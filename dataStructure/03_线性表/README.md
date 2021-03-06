# 线性表
## 线性表的定义
- **线性表(List):零个或多个数据元素的有限序列。**
  - 序列说明，元素之间是有序的;
  - 线性表强调是有限的，实际上无限的数列只存在于数学的概念中。

- 线性表的数学语言定义如下：
  - 若将线性表记为(a1,...,ai-1,ai,ai+1,...,an)，则表中ai-1领先于ai，ai领先于ai+1，称ai-1是ai的**直接前驱元素**，ai+1是ai的**直接后继元素**。当i=1,2,...,n-1时，ai**有且仅有一个直接后继**，当i=2,3,...,n时，ai**有且仅有一个直接前驱**。
  - 线性表元素的个数n(n>=0)定义为**线性表的长度**，当n=0时，称为**空表**。
  - 非空白表中每个数据元素都有一个确定位置，如a1是第一个数据元素，an是最后一个数据元素，ai是第i个数据元素，称i为数据元素ai在线性表中的**位序**。

- 在较复杂的线性表中，**一个数据元素可以由若干个数据项组成**，但**都有相同类型的数据**。(这就构成了实际表)

## 线性表的抽象数据类型
- 线性表的抽象数据类型定义如下：
```
ADT 线性表(List)
Data
	线性表的数据对象集合为{a1,a2,...,an},每个元素的类型均为DataType。其中，除第一个元素a1外，每一个元素有且只有一个直接前驱元素，除了最后一个元素an外，每一个元素有且只有一个直接后继元素。数据元素之间的关系是一对一的关系。
Operation
	InitList(*L); 初始化操作，建立一个空的线性表L
	ListEmpty(L); 若线性表为空，返回true,否则返回false
	ClearList(*L); 将线性表清空
	GetElem(L,i,*e); 将线性表L中的第i个位置元素值返回给e
	LocateElem(L,e); 将线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功，否则返回0表示失败
	ListInsert(*L,i,*e); 在线性表L中第i个位置插入新元素e
	ListDelete(*L,i,*e); 删除线性表L中第i个位置元素，并用e返回其值
	ListLength(L); 返回线性表L的元素个数
endADT
```

- 基于上述线性表定义好的基本操作，要实现复杂的个性化操作，即需要把简单的基本操作进行组合。

## 线性表的顺序存储结构

- 顺序存储定义
  - 线性表的顺序存储结构，指的是一段地址连续的存储单元依次存储线性表的数据元素。
- 线性表顺序结构的实现
  - 因为线性表的每个数据元素类型都相同，所以**用一维数组来实现顺序存储结构**。
  - 由下列代码，发现描述顺序存储需要三个属性
	- 存储空间的起始位置：
	- 线性表的最大存储容量：
	- 线性表的当前长度
	- 实际上还有线性表的元素类型。
  - 在任意时刻，线性表的长度应小于等于数组的长度。
```c++
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
```

- 地址计算方法
  - 存储器中的每个存储单元都有自己的编号，这个编号称为地址。
  - 假设每个数据元素都是要占据一定的存储单元空间，假设一个单元占据c个存储单元
	- 线性表中第i+1个数据单元的存储位置和第i个数据元素的存储位置满足：`LOC(a_(i+1))=LOC(a_i)+c`;
	- 线性表中第i个数据单元的存储位置和第1个数据元素的存储位置满足：`LOC(a_i)=LOC(a_1)+c*(i-1)`;
  - 由上述公式，可以随时算出线性表中任意位置的地址，不管存取哪个元素，都只需要进行一次操作，所以其**存取时间性能为O(1)**。通常把具有这一特点的存储结构称为**随机存取结构**。

## 顺序存储结构的插入与删除
- 获得元素操作
```c++
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

Status GetElem(SqList L,int i,ElemType *e)
{
	if (L.length==0||i<1||i>L.length)
		*e=L.data[i-1];//非指针不用->
		return OK;
}
```

- 插入操作
  - 如果线性表长度大于等于数组长度，则抛出异常(或动态增加容量);
  - 如果插入位置不合理，抛出异常;
  - 从**最后一个元素向前遍历到第i个位置**，分别将它们都向后移动一个位置;
  - 将要插入元素填入位置i处;
  - 表长加1。
```c++
Status ListInsert(SqList *L,int i,ElemType e)
{
	int k;
	if (L->length==MAXSIZE)
		return ERROR;
	if (i<1 && i>L->length+1)
		return ERROR;
	if (i<=L->length)
	{
		for (k=L->length-1;k>i-1;k--)
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;
	L->length++;//成员函数用this指针处理自加运算
	return OK;
	}
}
```

- 删除操作
  - 如果删除位置不合理，抛出异常
  - 取出删除元素
  - 从删除元素开始**向后遍历**到最后一个元素位置，分别将它们都向前移动一个位置;
  - 表长减1。
```c++
Status ListDelete(SqList *L,int i,ElemType *e)
{
	int k;
	if (L->length =0)
		return ERROR;
	if (i<1||i>L->length)
		return ERROR;
	*e=L[i-1];
	if(i<=L->length)//有可能上述条件只有i<1满足而不继续判断
	{
		for(k=i;k<L->length;k++)
		{	
			L->data[k-1]=L->data[k];
			k++;
		}
	}
	L->length--;
	return OK;//放在外面保证函数一定能结尾
}

```

- 线性表顺序存储结构的优缺点
  - 优点
	- 无须为表示表中元素直接的逻辑关系而增加额外的存储空间
	-可以快速地存取表中任一位置的元素
  - 缺点
	- 插入和删除操作需要移动大量元素
	- 当线性表长度拜年话较大时，难以确定存储空间的容量
	- 造成存储空间的碎片

## 线性表的链式存储结构

- 线性表链式存储结构
  - 定义：为了表示每个数据元素ai与其直接后继元素a_i+1之间的逻辑关系，对数据元素ai来说，除了存储其本身的信息之外，还需存储直接后继的存储位置。
	- 存储数据元素信息的域称为**数据域**;
	- 存储直接后继位置的域成为**指针域**;
	- 以上两部分信息组成数据元素ai的存储映像，称为**结点**(Node)。
  - **单链表**
	- n个结点链结成一个链表，即为线性表的链式存储结构，因为此链表的每个结点中只包含一个指针域，所以叫单链表。
  - **头指针**
	- 链表中第一个结点的存储位置叫做头指针
  - 线性链表的最后一个结点指针为NULL
  - 有时候，会在单链表的第一个结点前附设一个结点，称为**头结点**。
	- 头结点的数据域可以不存储任何信息
	- 头结点的指针域是指向第一个结点的指针

- 头指针和头结点的异同

| 头指针 | 头结点 |
| --- | --- |
| 头指针是指向第一个结点的指针，如果有头结点，则是指向头结点的指针 | 头结点是为了操作的统一和方便而设立的，放在第一元素的结点之前，其数据域一般无意义(也可存放链表的长度) |
| 头指针具有标识作用，所以常用头指针冠以链表的名字 | 有了头结点，对在第一元素结点前插入结点和删除第一结点，其操作与其他结点的操作就统一了 |
| 无论链表是否为空，头指针均不为空。**头指针是链表的必要元素。** | 头结点不是链表必须要素 |

- 线性表链式存储结构代码描述
```c++
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;//LinkeList就是Node*型,要不断new并且将指针传给上一个结点的指针域
```
.
### 单链表的读取
- 在单链表中，第i个元素到底在哪没法一开始就知道，必须从头开始找。
  - **获取链表第i个数据**的算法思路
	- 声明一个指针p指向链表第一个结点，初始化j从1开始;
	- 当`j<i`时，遍历链表，让p的指针向后移动，不断指向下一结点，j累加1;
	- 若到链表末尾p为空，则说明第i个结点不存在;
	- 否则查找成功，返回结点p的数据。

- 单链表读取的最坏情况的时间复杂度是O(n)。
  - 核心是“工作指针后移”，which is很多算法的常用技术。
```c++
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j=1;
	LinkList p;
	p = L->next;// point to 1st node
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if (!p)
		return ERROR;
	*e = p->data;
	return OK;
}
```

### 单链表的插入与删除
- 单链表的插入
  - 在p和p->next结点中间插入e结点
```c++
//顺序不能反
s->next=p->next;p->next=s;//s是Node*类型
```
- 单链表第i个数据插入结点的算法思路
  1. 声明一指针p指向链表头结点，初始化j从1开始;
  2. 当`j<i`时，遍历链表，让p的指针向后移动，不断指向下一结点，j累加1;
  3. 若到链表末尾p为空，则说明第i个结点不存在;
  4. 否则查找成功，在系统中生成一个新的空结点s;
  5. 将数据元素e赋值给`s->data`;
  6. `s->next=p->next;p->next=s;`并返回成功。

```c++
Status ListInsert(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p=*L;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p) return ERROR;
	
	s=new Node;
	p->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
```

- 单链表的删除
```c++
p->next=p->next->next;
```

- 单链表第i个数据删除结点的算法思路(先查找->查找成功后再删除)
  - 声明一个指针p指向链表头指针，初始化j从1开始;
  - 当`j<i`时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1;
  - 若到链表末尾p为空，则说明第i个结点不存在;
  - 否则查找成功，将欲删除的结点p->next赋值给q;
  - 进行链表结点的删除;
  - 删除值作为e的返回值;
  - 释放q结点;
  - 返回成功。

```c++
//delete非动态分配new的指针是非法的
//但链表结点指针通常是new出来的
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p,q;
	p=*L;
	j=1;
	while(p->next&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p) return ERROR;
	q=p->next;
	*e=q->data;
	p->next=q->next;
	delete q;//delete p->next->next;
	return OK;
}
```

- 以上操作分为两部分组成
  - **遍历查找第i个结点**
  - 插入和删除结点

- 单链表数据结构在插入和删除操作上与线性表相比没有太大优势，因为在查找上花费很多时间。
  - 但是**对于插入或删除数据越频繁的操作，单链表的效率优势就越是明显**。
  - 比如，从第i个位置，插入10个结点，对于顺序结构，每一次都要移动n-i个结点，而对于链表，只要进行一次查找，后续插入的时间复杂度都是O(1)。

### 单链表的整表创建

- 创建单链表就是一个动态生成链表的过程，即从空表的初始状态起，依次建立各元素结点。
  - 头插法
	1. 声明一指针p和计数器变量i;
	2. 初始化一空链表L;
	3. 让L的头结点指针指向NULL，即建立一个带头节点的单链表;
	4. 循环：
		- 生成一个新结点赋值给p;
		- 随机生成一数字赋值给p的数据域p->data;
		- 将p插入到头结点与前一新结点之间。
  - 尾插法
	1. 每次新插入的结点都放在最后。
```c++
/* 头插法 */
void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L) -> next = NULL;
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/* 尾插法 */
void CreateListTail(LinkList *L,  int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i=0;i<n;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

```
### 单链表的整表删除
- 算法思路如下
  1. 声明一结点p和q;
  2. 将第一个结点赋值给p;
  3. 循环：
	 - 将下一结点赋值给q;
	 - 释放p;
	 - 将q赋值给p。
```
//将L重置为空表
Status ClearList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;//剩下一个空结点
	return OK;
}
```
## 静态链表
- 对于没有指针的面向对象的语言，采用用**数组来代替指针**的形式描述单链表，即**静态链表**的形式来描述。
  - 数组元素采用两个数据域组成，data和cur，其中cur用于存放next指针，将cur叫做游标;
  - 数组的第一个和最后一个元素作为特殊元素，不存数据;
  - 未被使用的数组元素称为备用链表，数组第一个元素(下标为0的元素)的cur存放备用链表的第一个结点的下标;数组的最后一个元素的cur，存放第一个有数值的元素的下标，相当于单链表中的头结点的作用。
```c++
#define MAXSIZE 1000
typedef struct
{
	ElemType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];
```

```c++
//将一维数组space中各分量链成一备用链表
Status InitList(StaticLinkList space)
{
	int i;
	for (i=0;i<MAXSIZE;i++)
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
	return OK;
}

```
### 静态链表的插入操作
```c++
//若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;

	if(space[0].cur)
		space[0].cur=space[i].cur;
	return i;
}

```

```c++
//在L中第i个元素之前插入新的数据元素e
Status ListInsert(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k = MAX_SIZE - 1;
	if(i<1||i>ListLength+1)
		return ERROR;
	j = Malloc_SSL(L);
	if(j)
	{
		L[j].data = e;
		for(l = 1; l<=i-1; l++)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}
```

### 静态链表的删除操作
```c++
//删除在L中第i个数据元素e
Status ListDelete(StaticLinkList L,int i)
{
	int j,k;
	if(i<1||i>ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for(j=0;j<i;j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L,j);
	return OK;
}

void Free_SSL(StaticLikList space, int k)
{
	//改正备用链表
	space[k].cur = space[0].cur;
	space[0].cur = k;
}
```

- 计算静态链表长度/数据元素个数的函数
```c++
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur;
	while(i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
```
### 循环链表
- 将单链表中终端结点的指针端由空指针改为指向头结点，就使整个单链表形成一个环，这种头尾相接的单链表称为单循环链表，简称循环链表(cicurlar linked list)。
- 如果想用`O(1)`的时间由链表访问到最后一个结点，就需要用指向终端结点的尾指针`rear`来表示循环列表，此时查找开始结点和终端结点都很方便了。
```c++
//将两个循环链表合并成一个表时
p = rearA->next;
q = rearB->next;
rearA->next = q->next;
rearB->next = p;
free(q);
```

### 双向链表
- 双向链表(double linked list)是在单链表的每个结点中，再设置一个指向其前驱结点的指针域。
  - 因此双向链表中的结点都有两个指针域，一个指向直接前驱，一个指向直接后继。
```c++
//线性表的双向链表存储结构
typedef struct DulNode
{
	ElemType data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode, *DuLinkList;
```

- 双向链表插入结点
```c++
//将结点s插入到结点p和p->next之间
s -> prior = p;
s->next = p->next;
p->next->prior = s;
p->next = s;
```

- 双向链表删除结点
```c++
//将p结点从前驱和后继结点之中删除
p->prior->next = p->next;
p->next->prior = p->prior;
free(p);
```
