# 线程
线程是系统内核对象之一。内核对象是系统内核分配的一个内存块，该内存块描述的是一个数据结构，其成员负责维护对象的各种信息，内核对象的数据只能由系统内核来访问，应用程序无法在内存中找到这些数据并直接改变其内容。

系统内核对象有：事件对象、文件对象、作业对象、互斥对象、管道对象、进程对象和线程对象等。
不同类型的内核对象，其数据结构各有不同。

当一个进程创建时，系统会自动为其创建一个线程，该线程称为主线程，在主线程中用户可以创建其他线程，当进程中的主线成结束时，进程也就结束了。

基于线程的多任务处理是同一程序片段的并发执行
- 程序中的每个部分称为一个线程，每个线程定义一个单独的执行路径。

## win线程
win下函数`CreateThread`函数创建一个新的线程，新创建的线程必须要明确线程函数的起始地址。这个函数输入单个的参数并且返回一个DWORD值，一个进程可以有多个线程执行同一个函数。
- 原型函数介绍
```
//成功则返回新线程的handle，失败则返回NULL
//使用完毕后使用closeHandle进行关闭
HANDLE CreateThread(
_In_ 	SEC_ATTRS		SecurityAttributes,//指向SEC_ATTRS结构体的指针，决定返回的句柄是否可以被子进程继承
_In_ 	ULONG			StackSize,//栈的初始化字节数
_In_ 	SEC_THREAD_START 	StartFunction,//线程执行的具体函数
_In_ 	PVOID			ThreadParameter,//指向传递给线程的单个参数的指针
_In_ 	ULONG			CreationFlags,//控制线程创建的标识
_Out_	PULONG			ThreadId//指向接受线程标识符的变量
);

```

## POSIX线程
### 相关函数原型
头文件<pthread.h>
- 创建线程:`pthread_create(thread,attr,start_rotine, arg);`，创建成功返回0，返回值不为0则说明线程创建失败。
  - thread线程标识符指针
  - attr，属性对象，用于设定线程属性，不需要使用时只要指定NULL即可
  - start_routine，线程运行函数起始地址，线程执行的过程
  - arg，运行函数的参数，必须把引用作为指针强制转换为void类型进行传递，如果没有传递参数，则使用NULL
- 终止线程：`pthread_exit(status)`

线程标识符类型应为pthread_t，
