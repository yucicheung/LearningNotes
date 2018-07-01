# Python中的网络编程
主要使用scoket模块。模块中的socket()函数用于创建套接字，套接字会有自己的一套函数来提供基于套接字的网络通信。
## socket()模块函数
- `socket.socket()`函数语法
  - 函数原型：`socket(socket_family,socket_type,protocol=0)`
  - 参数说明
	- `socket_family`:[AF_UNIXAF_NETLINK,AF_INET];
	- `socket_type`:[SOCKET_STREAM,SOCKET_DGRAM];
	- `protocol`:一般不填，默认为0;
  - 使用实例如下
```python
# 创建一个TCP/IP的套接字
tcpSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 创建一个UDP/IP套接字
udpSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
```
- 通过上述函数套接字对象创建好以后，所有的**交互都将通过对该套接字对象的方法调用来进行**。

## 套接字对象(内建)方法
虽然主要讨论网络编程，但是这些方法在Unix套接字中也有类似含义。

| 函数 | 描述 |
| --- | --- |
| 服务器端套接字函数 | |
| `s.bind()` | 绑定地址(主机号，端口号对)到套接字 |
| `s.listen()` | 开始TCP监听 |
| `s.accept()` | 被动接受TCP客户端连接，(阻塞式)等待连接的到来 |
| 客户端套接字函数 | |
| `s.connect()` | 主动初始化TCP服务器连接 |
| `s.connect_ex()` | connect()函数的扩展版本，出错时返回出错码，而不是抛出异常 |
| 公共用途的套接字函数 | |
| `s.recv()` | 接收TCP数据 |
| `s.send()` | 发送TCP数据 |
| `s.sendall()` | 完整发送TCP数据 |
| `s.recvfrom()` | 接受UDP数据 |
| `s.sendto()` | 发送UDP数据 |
| `s.getpeername()` | 连接到当前套接字的远端的地址(TCP连接) |
| `s.getsockname()` | 当前套接字的地址 |
| `s.getsockopt()` | 返回指定套接字的参数 |
| `s.setsockopt()` | 设置指定套接字的参数 |
| `s.close()` | 关闭套接字 |
| 面向模块的套接字函数 | |
| `s.setblocking()` | 设置套接字的阻塞与非阻塞模式 |
| `s.settimeout()` | 设置阻塞套接字操作的超过时间 |
| `s.gettimeout()` | 得到阻塞套接字操作的超过时间 |
| 面向文件的套接字函数 | |
| `s.fileno()` | 套接字的文件描述符 |
| `s.makefile()` | 创建一个与该套接字关联的文件对象 |

## 实际编程
**运行网络编程的例子时，最好在不同的电脑之间运行服务器和客户端程序**。
- [创建一个TCP服务器](./02_createTcpServer.py)
```
# 伪代码
# 创建一个通用的TCP服务器
ss=socket()					# 创建服务器套接字
ss.bind()					# 把端口地址绑定到套接字上，服务器进程从该端口监听请求
ss.listen()					# 监听连接
inf_loop:					# 服务器无限循环
	cs = ss.accept()		# 接受客户端连接
	comm_loop:				# 通信循环
		cs.recv()			# 接受
		cs.send()			# 发送
	cs.close()				# 关闭客户端套接字
ss.close()					# 关闭服务器套接字（可选)

# 附加注释
# 对于单线程的服务器会调用accept()函数等待连接的到来
# 默认情况下accept函数是阻塞式，即程序在连接到来之前会处于挂起状态。（套接字也支持非阻塞模式）
```

