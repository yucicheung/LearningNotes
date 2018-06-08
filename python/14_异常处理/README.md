# 异常处理
## 基础
- `finally`子句是无论异常是否发生是否捕捉都会执行的一段语句，它常常用来维护程序的一致无论异常是否发生


## 高级
0. 异常处理通用tips
  - 可以在抛出的异常上使用关键字`as`;
  - except子句是按照列出的顺序进行检查的，执行第一个匹配的子句;
  - 异常通常有自己的继承体系，要确定某个特定异常的类层次结构可以用检查异常的`__mro__`属性进行查询，如`FileNotFoundError.__mro__`;

6. 用一个代码块处理多个异常
  - 可以将它们归组在同一个元组中;
  - 因为异常通常都有继承体系，因此可以选择一个共同基类表示所有的错误类型;

```python
//错误归类在元组中
try:
	client_obj.get_url(url)
except (URLError,ValueError,SocketTimeOut):
	client_obj.remove_url(url)

//选择共同基类捕获所有的错误类型
try:
	f=open(filename)
except OSError://FileNotFoundError和PermissionError都是其子类
	...
```
7. 捕获所有异常
  - 可以为`Exception`类编写一个异常处理程序
	- 如果也想捕获`SystemExit``KeyboardInterrupt`和`GeneratorExit`这几个错误，需要将基类改成`BaseException`
	- 在处理异常时最好还是尽可能使用精确的异常类，否则就必须要提供高质量的诊断信息，或者将异常信息传播出去而不致丢失异常信息，如
```python
def parse_int(s):
	try:
		n=int(v)
	except Exception as e:
		print('Reason:',e)
```

8. 创建自定义异常：对底层的异常进行包装从而打造自己的异常类
  - 方法：将异常定义成继承自Exception的类即可(也可以继承自其他异常类，如果这么做更有道理的话)
  - **自定义的异常类应总是继承自内建的Exception类或一些本地定义的基类(此基类应继承自Exception类)**：BaseException类是用来通知应用程序退出的，因此如果将自定义类继承自它，异常无法捕获也不会让程序关闭
  - 好处：使阅读代码的人更好地理解程序的行为，一种设计是通过继承机制将自定义的异常归类到一起，在复杂的应用中引入更高层的基类将不同的异常类归组到一起，因此可以捕获细粒度错误的能力，但同样也能够捕获粗粒度范围的错误
  - 如果定义一个新的异常并改写Exception的__init__()方法，请确保总是用所有的传递过来的参数调用Exception.__init__()方法，因为Exception的默认行为就是接受所欲传递过来的参数并将它们以元组的形式保存到.args属性中，如果异常没有一个args属性(不满足各组件及各种库的期望)，则新创建的异常在特定上下文环境中会表现出不正确的行为。
```python
//创建自定义异常类的方法
class NetworkError(Exception):
	pass

class HostnameError(NetworkError):
	pass

class TimeoutError(HostnameError):
	pass

class ProtocolError(TimeoutError):
	pass

////捕获细粒度异常
try:
	s.send(msg)
except NetworkError:
	...
////捕获粗粒度异常
try:
	s.send(msg);
except NetworkError:
	...

//创建新异常时重写__init__方法用所有参数初始化该方法
class CustomError(Exception):
	def __init__(self, message, status):
		super().__init__(message, status):
		self.message = message
		self.status = status
//全部参数初始化__init__方法的效果，参数均保存在args属性中
try:
	raise RuntimeError('It failed')
except RuntimeError as e:
	print(e.args)

```


