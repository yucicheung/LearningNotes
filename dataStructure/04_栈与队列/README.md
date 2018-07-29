# 第4章 栈与队列
- **栈**：限定在表尾进行插入和删除操作的线性表。
- **队列**：只允许在一端进行插入操作，而在另一端进行删除操作的线性表。
## 栈的定义
网页浏览的“回退”，编辑软件中的undo操作，都是用栈的方式实现的。
- **栈(stack)**：是限定仅在表尾进行插入和删除操作的线性表。
  - 允许插入和删除的一端称为**栈顶(top)**;另一端称为**栈底(bottom)**;
  - 不含任何数据元素的栈称为空栈;
  - 栈又称为后进先出(Last In First Out,LIFO)的线性表，简称LIFO结构。
- 栈的插入，删除操作只在栈顶进行
  - 栈的插入操作，叫做**进栈，也称压栈、入栈**;
  - 栈的删除操作，叫做**出栈**，也叫弹栈。
如果是1,2,3三个数字，会有5种可能的出栈次序，一定不可能是`312`这种出栈次序。

## 栈的抽象数据类型
- 栈的插入和删除操作，称为push和pop;
```c++
ADT 栈(stack)
Data
	同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
Operation
	InitStack(*S):初始化操作，建立一个空栈S
	DestroyStack(*S):若栈存在，则销毁它
	ClearStack(*S):将栈清空
	StackEmpty(S):若栈为空，返回true;否则返回false
	GetTop(S,*e):若栈存在且非空，用e返回S的栈顶元素
	Push(*S,e):若栈S存在，插入新元素e到栈S中并成为栈顶元素
	Pop(*S,*e):删除栈S中栈顶元素，并用e返回其值
	StackLength(S):返回栈S的元素个数
endADT
```
- 栈的结构定义
  - `top`为栈顶指针，空栈时top=-1，栈满时top=MAXSIZE-1;
```c++
typedef int SElemType;
typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;
```

- 进栈操作push
  - 无循环操作，时间复杂度O(1)
```c++
//插入元素e为新的栈顶元素
Status Push(SqStatus *S, SElemType e)
{
	if(S->top ==MAXSIZE -1) return ERROR;
	s->top++;
	s->data[s->top]=e;
	return OK;
}
```

- 出栈操作pop
  - 时间复杂度为O(1)
```c++
//若栈不空，则删除S栈顶元素，用e返回其值，并返回OK;否则返回ERROR
Status Pop(SqStack *S,SElemType *e)
{
	if(S->top==-1) return ERROR;
	*e= S->data[S->top];
	S->top--;
	return OK;
}
```

### 两栈共享空间
数组有两个端点，两个栈有两个栈底，让一个栈的栈底为数组的始端，另一个栈为数组的末端，即下表为数组长度n-1处。则如果两个栈增加元素，就是两端点向中间延伸。
- **关键思路**是：它们是在数组两端，向中间靠拢，top1和top2是栈1和栈2的栈顶指针，只要两者不见面，就可以一直使用。
  - 栈1为空时，top1==-1;栈2为空时，top2==n;
  - 当top1+1==top2时，栈满。
```c
//两栈共享空间结构
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;
```

- 在插入元素到两栈共享空间时，需要有一个判断是栈1还是栈2的栈号参数stackNumber，插入元素的代码如下
```c
Status Push(SqDoubleStack *S,SElemType e,int StackNumber)
{
	if(S->top1+1==S->top2)return ERROR;
	if(StackNumber==1)
	{
		S->top1++;
		S->data[S->top1]=e;
	}
	else if(StackNumber==2)
	{
		S->top2++;
		S->data[S->top2]=e;
	}
	return OK;
}
```

- 两栈共享的pop方法
```c
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK;否则返回ERROR
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{
	if(stackNumber==1)
	{
		if(S->top1==-1)return ERROR;
		*e=S->data[S->top1--];
	}
	else if(stackNumber==2)
	{
		if(S->top2==MAXSIZE)return ERROR;
		*e=S->data[S->top2++];
	}
	return OK;
}
```

### 栈的链式存储结构及实现
- 栈的链式存储结构：**链栈**
  - 将栈顶放在单链表的头部;
  - 空链栈就是`top=NULL`。
```c
typedef struct StackNode
{
	SElemType data;
	sruct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

```
![链栈示意图]()

- 进栈操作
  - 进栈push操作，假设元素值e的新结点是s，top为栈顶指针
  - 时间复杂度O(1)
```c
//插入元素e为新的栈顶元素
Static Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s=(LinkStackPtr) malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;	//S stands for LinkStack
	S->top = s;			//s stands for node
	S->count ++;
	return OK;
}
```

- 出栈操作
  - 时间复杂度O(1)
```c++
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK;否则返回ERROR
Status Pop(LinkStack *S,SElemType *e)
{
	LinkStackPtr p;
	if(StackEmpty(*S))return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	s->count--;
	return OK;
}

```

### 栈的应用--递归
栈有一个很重要的应用：**在程序设计语言中实现了递归**。
- 把直接调用自己或一系列的调用语句间接地调用自己的函数，称做递归函数。每个递归定义必须至少有一个条件，满足时不再进行，即不再引用自身而是返回值退出。
- 用栈实现递归的方法是
  - 在前行阶段，对于每一层递归，函数的局部变量、参数值以及返回地址都被压入栈中。
  - 在退回阶段，位于栈顶的局部变量、参数值和返回地址被弹出，用于返回调用层次中执行代码的其余部分，也就是恢复了调用的状态(恢复上一层的调用状态)。

#### 后缀(逆波兰)表示法
程序设计四则运算表达式的难点：关于运算顺序的控制。解决方案是用**括号**。
- 括号是成对出现的，有左括号就一定有右括号，对于多重括号，最终也是完全嵌套匹配的。
  - 只要碰到左括号就将左括号进栈，出现右括号就让左括号出栈，期间让数字运算。
  - 栈应该从空到有元素，最后又因全部匹配成功成为空栈。

而**一种不需要括号的后缀表示法**，我们也把它叫做逆波兰(Reverse Polish Notation,RPN)表示。
比如原表达式是`9+(3-1)x3+10/2`(**中缀表达式**)，那相应的后缀表示式就是`9 3 1-3*+10 2/+`。
- 规则是：从左到右遍历中缀表达式的每个数组和符号，若是数字就输出，即成为后缀表达式的一部分;若是符号，则判断其与栈顶符号的优先级，是**右括号或优先级不高于栈顶符号(乘除优先加减)则栈顶元素依次进栈并输出，并将当前符号进栈**。直至最终输出后缀表达式为止。

- 因此想要让计算机具有处理我们常用的标准表达式的能力，主要就是分为以下两步。而整个过程都充分利用了栈的LIFO特性。
  1. 将中缀表达式转化为后缀表达式(栈用来进出运算的符号);
  2. 将后缀表达式进行运算得出结果(栈用来进出运算的数字)。

### 队列的定义
操作系统和客服系统中，都是应用了一种数据结构来实现先进先出的排队功能，即队列。
- **队列是只允许在一端进行插入操作，而在另一端进行删除操作的线性表**。
  - 队列是一种先进先出(FIFO)的线性表。
  - 允许插入的一端称为队尾，允许删除的一端称为队头。

- 队列的抽象数据类型
```
ADT 队列(Queue)
Data
	同线性表。元素具有相同的类型，相邻的元素具有前驱和后继关系
Operation
	InitQueue(*Q):初始化操作，建立一个空队列Q
	DestroyQueue(*Q):若队列存在，则销毁它
	ClearQueue(*Q):将队列Q清空
	QueueEmpty(Q):若队列为空，则返回True;否则返回False
	GetHead(Q,*e):若队列存在且非空，用e返回队列Q的队头元素
	EnQueue(*Q,e):若队列Q存在，插入新元素e到队列Q中并成为队尾元素
	DeQueue(*Q,*e):删除队列Q中队头元素，并用e返回其值
	QueueLength(Q):返回队列Q的元素个数
endADT
```

front指向队头元素，rear指针指向队尾元素的下一个位置，当front等于rear时，此队列不是只剩一个元素，而是空队列(rear-front等于元素个数)。但是如果只是线性排列，即前面还有空位时，指针却只向后移动导致数组越界，这就是“假溢出”。解决假溢出的方法是后面满了，就再从头开始，即头尾相接的循环。把**队列的头尾相接的顺序存储结构称为循环队列**。
但是又有另外一个问题：当front==rear时，如何判断队列是满还是空？
- 方法一：设置flag，表示队列是否为空．
- 方法二：在队列中保留一个元素空间，即队列满时，数组中也还有一个空闲单元。

重点讨论方法二(队列满也会保持一个空闲单元)，rear和front的值都小于QueueSize。
- **队满的条件**:`(rear+1)%QueueSize == front`;
- 通用的计算**队列长度**公式为:`(rear-front+QueueSize)%QueueSize`。

- 循环队列的顺序存储结构代码
```c
typedef int QElemType;
typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;
```

- 循环队列的初始化代码
```c
//初始化一个空队列Q
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return OK;
}
```

- 循环队列求长度
```c
//返回Q的元素个数，也就是队列的当前长度
int QueueLength(SqQueue Q)
{
	return (MAXSIZE+Q->rear-Q->front)%MAXSIZE;
}
```

- 循环的入队操作代码
```c
//若队列未满，插入元素e为Q新的队尾元素
Status EnQueue(SqQueue *Q, QElemType e)
{
	if( (Q->rear+1)%MAXSIZE==Q->front )
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear=(Q->rear+1)%MAXSIZE;

	return OK;
}
```

- 循环队列的出队列操作代码
```c
//若队列不空，则删除Q中队头元素，用e返回其值
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if(Q->front == Q->rear) return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front) % MAXSIZE;

	return OK;	
}
```
### 队列链式存储结构及实现

