## POSIX线程
为实现可移植的线程程序，IEEE在IEEE标准1003.1c中定义了线程的标准，它定义的线程包叫**pthread**。大部分UNIX都支持该标准。该标准定义了超过60个函数调用。
这里只列举一些主要函数及其工作描述。

| 线程调用 | 描 述  |
| --- | --- |
| pthread_create | 创建一个新线程 |
| pthread_exit | 结束调用的线程 |
| pthread_join | 等待一个特定的线程退出 |
| pthread_yield | 释放CPU来运行另外一个线程 |
| pthread_attr_init | 创建并初始化一个线程的属性结构 |
| pthread_attr_destroy | 删除一个线程的属性结构 |

所有pthread线程都有某些特性，每一个都包含
- 一个标识符
- 一组寄存器(包括程序计数器)
- 一组存储在结构中的属性：属性包括堆栈大小、调度参数以及其他线程需要的项目。

注意：一个线程逻辑上没有阻塞，但是感觉上它已经运行了足够长的时间并且希望给另外一个线程机会去运行，这时候就调用`pthread_yield`完成这一目标。进程间却没有这种调用，因为**进程间通常是竞争关系**（每个进程都希望获得所有的CPU时间），但是**线程之间通常会希望可以同时工作**，会希望给对方一些机会去运行。

实现线程包有两种主要的方法：
1. 在用户空间中
2. 在内核中

## 在用户空间中实现线程
把整个线程包放在用户空间中，内核对线程包一无所知，从内核角度考虑，就是按照正常的方式管理，即单线程进程。
优点：用户级线程包可以在不支持线程的操作系统上实现。

以下是一个简单的用户空间中创建线程的办法：
```c
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define NUMBER_OF_THREADS 10

void* print_hello_world(void *tid)		//每个线程运行的函数，过程
{
	printf("Hello World.Greetings from thread %d\n",tid);
	pthread_exit(NULL);
}

int main(int argc,char*argv[])
{
	pthread_t threads[NUMBER_OF_THREADS];
	int status,i;

	for(i = 0;i<NUMBER_OF_THREADS;i++)
	{
		printf("Main here.Creating thread/n");
		status = pthread_create(&threads[i],NULL,print_hello_world,(void*)i);//i传入给ptint_hello_world为其输入参数

		if(!status==0){
			printf("pthread_create returned error codes %d./n",status);
			exit(-1);
		}
	}
	exit(NULL);
}
```

其中，函数原型为
- `int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void* (*start_routine)(void*),void *arg)`;
- `void pthread_exit(void* retval)`
  - 其中retval是一个地址，函数的返回状态会被存储到对应地址，而该状态通常会用来和`pthread_join()`进行配合。

在用户空间管理线程时，每个进程需要有其专用的**线程表(thread table)**，用来跟踪进程中的线程，它仅记录各个线程的属性：如每个线程的程序计数器、堆栈指针、寄存器和状态等。该线程表由运行时系统管理，而不由内核管理。当一个线程转换到就绪状态或阻塞状态时，线程表中会存放重新启动该线程所需的信息，与内核在进程表中存放进程的信息完全一样。

用户空间的线程和内核空间的进程的差别
- 保存线程状态的过程和调度程序都只是本地过程，所以启动它们比进行内核调用(进程)效率更高；
- 另一方面，不需要陷入内核，不需要上下文切换，也不需要对内存高速缓存进行刷新，这使得线程调度非常快捷。

用户级线程相比内核线程的优点
- 它允许每个进程有自己定制的调度算法。
- 也会有比较好的可扩展性(因为在内核空间中内核线程需要一些固定表格空间和堆栈空间，内核线程数量过大会出现问题)。
