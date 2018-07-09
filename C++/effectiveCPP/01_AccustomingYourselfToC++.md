# 让自己习惯C++

## 条款01:视C++为一个语言联邦--View C++ ad a federation of languages
一开始C++只是C加上一些面向对象特性，最初的名称`C with Classes`也反映了这个关系。但后来的C++逐渐发展得更大胆。

- 今天的C++已经是个多重范型编程语言(multiparadigm programming language)，同时支持以下形式。 因为这些能力，C++已是一个无可匹敌的工具，
  - 过程形式(procedural)
  - 面向对象形式(object-oriented)
  - 函数形式(funcitonal)
  - 泛型形式(generic)
  - 元编程形式(metaprogramming)
	- 元编程Meatprogramming：是指某类计算机程序的编写，这类计算机程序编写或操控其他程序作为它们的数据(比如cmake操控Cpp文件)，或者在运行时完成部分本该在编译时完成的工作。

-对C++的最简单的理解方法是**将C++视为一个相关语言组成的联邦而非单一语言**，在某个次语言(sublanguage)中，各种守则与通例都倾向简单、直观易懂、并且容易记住。但当从一个次语言迁移到另一个次语言时，守则可能改变。C++主要的次语言有四个：
  - **C**
	- 说到底C++仍是以C为基础，区块(blocks)、语句(statements)、预处理器(preprocessor)、内置数据类型(bulit-in data types)、数组(arrays)、指针(pointers)等均来自C。
	- 许多时候C++对问题的解法就是较高级的C解法。但以C++内的C成分工作时，高效编程守则反映出C语言的局限：没有模板(templates)、没有异常(exceptions)、没有重载(overloading)...
  - **Object-Oriented C++**
	- 即`C with classes`所诉求的：classes(包括构造函数和析构函数)，封装(encapsulation)、继承(inheritance)、多态(polymorphism)、virtual函数(动态绑定)...
	- 这部分是面向对象设计守则在C++上的最直接体现。
  - **Template C++**
	- C++的泛型编程(generic programming)部分。
	- Template相关考虑与设计已经弥漫整个C++。
	- 实际上由于templates威力强大，它们带来的崭新的编程范型(programming paradigm),即所谓的templates metaprogramming(TMP，模板元编程)。
  - **STL**
	- STL是个template程序库，但它是非常特殊的一个。
	- 它对容器(containers)、迭代器(iterators)、算法(algorithms)以及函数对象的规约有极佳的紧密配合与协调，然而templates及程序库也能以其他想法建置出来。
	- STL有自己特殊的办事方式，必须遵守它的规约。

- 当从某个次语言切换到另一个次语言时，高效编程守则会要求你改变策略。记住以上4个次语言及其各自的规约，就会更容易了解C++。

## 条款02:尽量以const,enum,inline替换#define————Prefer consts,enums,and inlines to #defines

**宁可以编译器替换预处理器**。

记住：
- 对于单纯常量，最好以const对象或enums替换#defines
- 对于形似函数的宏(macros)，最好改用inline函数替换#defines。
