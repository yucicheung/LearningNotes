# 14 C++工具
## 异常处理
### 概念
- 错误分为
  - 语法错误，是在编译阶段发现的错误，因此也叫*编译错误*
  - 运行错误
- 异常处理机制
  - `try-catch`结构+`throw`语句
  - 一般在执行`throw`语句后，程序会立即离开`try`语句，从而转向`catch`异常处理块，然后执行`catch`以后的语句。
```c++
//try catch
try
	{被检查的语句}
catch (异常处理信息类型 [变量名])
	{进行异常处理的语句}
//throw
throw 表达式;
```
- `try-catch`语句
  - `try`块是不能缺少的，`catch`块可以缺少;
  - `try`及`catch`块的语句必须有花括号;
  - 一个`try-catch`结构只能有一个`try`块，但是可以有多个`catch`块;
  - `catch`后圆括号中一般只写异常信息类型名`catch(double);`，如果要用到特定的变量，还可以指定变量名`catch (double d);`;
  - 如果`catch`跟着`...`表示可以捕捉任何类型的异常消息，类似于`其他`选项;
- `throw`
  - `throw`抛出异常以后，便直接离开本函数。
  - `throw`抛出异常以后，首先在本函数中寻找与之匹配的`catch`，如果本层找不到，就转到上一层(这里的都是函数嵌套的层级)处理。即会转到离出现异常最近且类型能够匹配的`try-catch`结构去处理。
  - `throw`语句可以不包括表达式，直接`throw;`将下级传过来的异常不做处理，而直接抛给上层。
  - 如果`throw`抛出的异常一直(到了最高层)没有找到与之匹配的`catch`块，系统就会调用一个terminate系统函数使程序终止。
### 在函数声明中进行异常情况指定
- C++允许在声明函数时列出可能抛出的异常类型，*异常指定*是函数声明的一部分，并且**必须在函数声明和函数定义的首行同时出现**。
  - `double triangle(double,double,double) throw(double);`表示允许抛出double型的异常;
  - `double triangle(double,double,double) throw(int,double,float,char);`允许抛出四种类型的异常;
  - `double triangle(double,double,double) throw();`声明一个不能抛出异常的函数，即使语句中有`throw`也并不执行。
### 在异常处理中的析构函数
- C++的异常处理机制会在`throw`语句抛出**异常信息被`catch`捕获前，对相关局部对象进行析构**。
  - **析构的顺序是*与构造的顺序相反**。
## 命名空间
### 概念
- 名字冲突：即重复定义，在同一个作用域内有两个或多个同名实体。
- 命名空间的作用是建立一些相互分隔的作用域，把一些全局实体分隔开来，以免产生名字冲突。
- 这种用法叫*命名空间限定*，`nsl::a`这种名字叫做*被限定名*。
- 命名空间组成
  - 命名空间关键字`namespace`;
  - 命名空间名`nsl`;
  - 命名空间成员
	- (常)变量
	- 函数;
	- 结构体/类;
	- 模板;
	- 命名空间;
  - **不能包含预处理指令**。
```c++
namespace nsl
{
const int RATE;
double pay;
double tax()
	{return a*RATE;}
namespace ns2
	{int age;}
}
```
- 过去的全局变量可以理解为*全局命名空间*，独立于所有有名的命名空间之外。名字`ns1::RATE`称为*被限定名*。
- **注意**
  - 声明类时最后会有一个分号，而声明命名空间时没有分号。
  - 即使建立了新的命名空间，要进行标准输入输出就仍然需要使用`using namespace std;`。
### 使用
- 有名的命名空间
  - 使用命名空间别名;
	```c++
	namespace Television
	{...}
	namespace TV=Television;//给命名空间Television别名设置为TV
	```
  - 使用`using 命名空间成员名;`
	```c++
	using nsl::Student;
	```
  - 使用`using namespace 命名空间名;`
	```c++
	using namespace nsl;
	```
  - **注意**：仅在命名空间数量很少，以及确保这些命名空间中没有同名成员时才用`using namespace`语句。
- 无名的命名空间
  - 在文件中使用无名的命名空间，不必也不能用命名空间名限定;
  - 无名的命名空间作用就是把成员的作用域限制在本文件内。
```c++
namespace
{
void fun(){cout<<"OK."<<endl;}
}
```

- 标准命名空间std(表示这是存放标准库的有关内容的命名空间)
  - 标准C++库的所有标识符都是在一个名为`std`的命名空间中定义的，或者说标准头文件中的函数、类、对象和类模板都是在命名空间std中定义的。
- 如果使用`using namespace std;`,应该需要保证在程序不出现与命名空间`std`中的成员同名的标识符。
