# Java基本程序设计结构

## 8控制流程

### 循环
- `while`循环
```java
while(condition) statement
```

- `do-while`循环
  - 至少执行一次的循环体
```java
do statement while (condition);
``` 

- `for`循环（确定循环）
  - 支持迭代的一种循环
  - 允许在for循环的各部分放置任何表达式，但是语句的3个部分应当对同一个计数器变量进行初始化、检测和更新，否则循环常常晦涩难懂。
  - 在for循环中声明/定义的变量，作用域仅限于for语句内部。
  - for是while循环的一种简化形式，因为for的功能充分可以用while来实现。
```java
for (int i = 10; i > 0;i--)
 System.out.println("Counting down..."+i);
System.out.println("Blastoff");
```

- `switch`多重选择语句
  - Java的该语句与C/C++完全相同
  - 有可能触发多个case分支，如果在case分支语句末尾没有break的话。
	- 为了使编译器给出相关警告，可以利用`javac -Xlint:fallthrough Test.java`的选项进行编译。
	- 但是如果是需要直通式(fallthrough)行为，可以在其外围加一个标注`@SuppressWarnings("fallthrough")`，这就可以避免对该方法生成警告了。(标注是向编译器等java处理工具提供信息的一种机制)
	- case标签可以是1.类型为char,byte,short或int的常量表达式;2.枚举常量;3.Java SE7后还可以是字符串字面量。
	- switch语句中使用枚举常量时，不必在每个标签中指明枚举名。可以由switch的表达式值确定。
```java
switch (choice)
{
	case 1:
		...
		break;
	case 2:
		...
		break;
	default:
		...
		break;
}
//枚举常量的例子
Size sz = ...;
switch (sz)
{
	case SMALL://no need to use Size.SMALL
		...
		break;
	...
}
```
- 中断控制流程语句
  - `goto`语句
	- 虽然Java中goto是保留字，但实际上并没有打算在语言中使用它。
	- 无限制使用`goto`可能导致很多错误，但是偶尔使用`goto`跳出循环还是有益的。
  - `break`语句
	- 用一条带标签的`break`来实现`goto`*跳出循环*的功能。(其实不用break也是可以的，但是可能会造成重复检测等浪费运算资源的情况)。
	- 带标签的`break`主要用于跳出多重嵌套的循环。此时**标签必须放置在希望跳出的最外层循环之前，并且紧跟一个冒号**。会跳到与标签匹配的语句**尾部**。
	- 实际上，**可以将标签应用于任何语句(语句块)中**。
	- 只能跳出不能跳入语句块。
  - continue语句
	- 中断正常的控制流程，将控制转移到最内层循环的首部。
	- 当这个循环是for循环时，会跳到for循环的"更新"部分，如`for (count=1;count<=100;count++)`中的`count++`部分。
	- 带标签的`continue`会跳到与标签匹配的循环首部。
  - break跳到语句尾，continue到语句首部。
```java
//-----------break------------------------
label:
{
	...
	if (condition) break label;//exists block
	...

}
//jumps here when the break statement executes
```

- 大数值(*********************stop here********************you need to write code for this part babe)**
  - 

## 警告

- 浮点数的比较需要特别小心，因为0.1是无法精确地用二进制表示的。
