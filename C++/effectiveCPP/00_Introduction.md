# 导读

没有一个条款放之四海皆准，本书做的只是提供指南。

## 术语
- 声明式(declaration)是告诉编译器某个东西的名称和类型，但略去细节。
  - 每个函数的声明揭示其**签名式**(signature)，即**参数和返回类型**。一个函数的签名等同该函数的类型，C++对签名式的官方定义并不包括函数的返回类型，但本书将返回类型视为签名的一部分。

- 定义式(definition)的任务是提供编译器一些声明式所遗漏的细节
  - 对对象，定义时是编译器为此对象拨发内存的地点;
  - 对function/function template，定义式提供代码本体;
  - 对class/class template，定义式列出其成员。

- 初始化(initialization)是“给予对象初值”的过程。
  - 对用户自定义类型的对象而言，初始化由构造函数执行;
  - **default构造函数**是一个可被调用而不带任何实参者，这种构造函数要么就没有参数，要不就是每个参数都有缺省值;
```c++
class C{
public:
	explicit C(int x);//不是default构造函数
}
```

- 上述构造函数中`explicit`，可以阻止它们被用来执行隐式类型转换(implicit type conversions)，但它们仍可以用来进行显式类型转换(explicit type conversions)。
  - `隐式类型转换`指隐式将char转为int，从short转为double以进行运算间的数据类型统一。
  - 被声明为explicit的构造函数通常比其non-explicit兄弟更受欢迎，因为它们禁止编译器执行非预期(往往也不被期望)的类型转换。**除非有一个好理由允许构造函数被用于隐式类型转换，否则会把它声明为explicit，**作者鼓励大家遵循同样的政策。

```c++
void doSomething(B bOject);

B bObj1;
doSomething(bObj1);
B bObj2(28);//错误，doSomething应该接受一个B，而不是一个int类型，而int到B之间没有隐式转换

doSomething(28);

doSomething(B(28));//使用B构造函数将int显式转换(也就是转型cast)为一个B以促成此一调用

```

- copy构造函数被用来“以同型对象初始化自我对象”，copy assignment操作符被用来“从另一个同型对象中拷贝其值到自我对象”
  - **注意**:`=`语法也可以用来调用copy构造函数。但**"copy构造"很容易和"copy赋值"有所区别**，如果一个新对象被定义，一定会有个构造函数被调用，不可能用赋值操作。如果没有新对象被定义，自然就是赋值操作被调用。
```c++
class Widgets{
public:
	Widget();								//default构造函数
	Widget(const Widget& rhs);				//copy构造函数
	Widgets & operator=(const Widget&rhs);	//copy assignment操作符
	...
};
Widget w1;			//调用default构造函数
Widget w2(w1);		//调用copy构造函数
w1 = w2;			//调用copy assignmet操作符

// 注意!!!用=调用copy构造函数
Widget w3=w2;		//调用copy构造函数

```

- **`copy`构造函数**是一个尤其重要的函数，因为它是**定义**一个对象如何passed by value(以值传递)
  - 下述调用中，aWidget被复制到w体内，这个复制动作由Widget的copy构造函数完成;
  - **pass-by-value意味着“调用构造函数”**。
  - 以by value传递用户自定义类型通常是个坏注意，Pass-by-reference-to-const往往是比较好的选择。 
```c++
bool hasAcceptanbleQuality(Widget w);
...
Widget aWidget;
if (hasAcceptableQuality(aWidget))...
```

- STL是所谓标准模板库(Standard Template Library)，是C++标准程序库的一部分，致力于容器(如vector,list,set,map等)、迭代器(如vector<int>::iterator,set<string>::iterator等等)、算法(如for_each,find,sort等)及相关机能。
  - 许多**相关机能**以函数对象(function objects)实现，那是行为"象函数的对象"，这样的对象来自于重载operator()（function call操作符）的classes(例如我们对重载操作的定义)。

- C++的"不明确行为"(*undefined behavior*)：某些C++构件的行为没有定义，你无法稳定预估运行期会发生什么事。
```c++
int *p=0;				//p是个null指针，不是指向一个变量
std::cout<<*p;			//对一个null指针取值(derenferencing)
						//会导致不明确行为
char name[] = "Darla";	
char c = name[10];		//指涉一个无效的数组索引导致不明确行为
```

- 接口(interface)，但我们谈论C++中的接口时，完全是指一般性的设计观念(不同于Java和C#中将Interfaces作为语言元素)。我们一般谈论的是
  - 函数的签名(signature)
  - class的可访问元素(如class的“public接口”、“protected接口”、“private接口”)
  - 或者是针对template类型参数需为有效的一个表达式。

- 客户(Client)指某人或某物，ta使用你的代码（通常是一些接口，也可以是类）。

## 命名习惯(Naming Conventions)
作者自身的命名习惯

- `lhs`和`rhs`(for `left-hand side`和`right-hand side`)常作为二元操作符函数如`operator==`和`operator *`的参数名称;
	- 假设a和b表示两个有理数对象，如果Rational对象可以被一个`non-member operator*`函数执行乘法，那么`a*b`等于`operator*(a,b)`的调用，此操作函数的声明就会是
```c++
const Rational operator*(const Rational & lhs, const Rational& rhs);//左操作数是lhs,右操作数是rhS
```

- 如果对于成员函数，左操作数a变成函数内的**this**，右操作数变成rhs。
  - 成员函数左侧实参可以由this表现。

- 关于指针的命名：一般"pointer to T"，指向一个T型对象被命名为`pt`
- 类似的，关于references的类似命名习惯，`rw`可能是"reference to Widget",而`ra`是个"reference to Airplane"。
- 成员函数，偶尔以`mf`命名。

```c++
Widget* pw;		//ptr to Widget
class Airplane;
Airplane* pa;	//ptr to Airplane
```

## 关于线程(Thread Consideration)
- C++对线程(threads)没有任何意念————事实上它对于任何并发(concurrency)事物都没有意念。但实际应用中，可能经常需要考虑线程安全性(thread safety)。
  - 作者的处理方式是，如果所检验的C++构件在多线程环境中有可能引发问题，就把它指出来。

## TR1和Boost
- TR1("Technical Report 1")是一份规范，描述加入C++标准程序库的诸多新机能，这些机能以新的class templates和function templates形式体现，针对的主题有hash table, reference-counting smart pointers, regular expressions等。
  - 所有TR1组件都在命名空间tr1内，后者嵌套于命名空间std内。

- Boost是个组织，也是个网站，提供可移植、peer review、源码开放的C++程序。大多TR1机能是以Boost的工作为基础。

