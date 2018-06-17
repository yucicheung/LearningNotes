

## design pattern
- 观察者模式/observer pattern
  - 在此种模式中，一个目标对象管理所有相依于它的观察者对象，并且在它本身的状态改变时主动发出通知。这通常通过呼叫各观察者所提供的方法来实现，此种模式通常被用来实时事件处理系统。

## Linked with the compiler

- DLL and lib(二进制文件)
  - 静态链接库(LIB)是直接链接到可执行文件。静态库是一些要经常被调用的代码，为避免每次使用都要重新编译，会把经常被调用的*可执行代码*放在一个LIB里面，linker就会将编译好的代码提取并插入在程序当中。因此静态库也因此称为"档案(archive)"。
  - 动态链接库DLL更进一步，在每个程序中对静态库中的函数做多次拷贝会造成空间的浪费，动态库使它们可以**共享同一份函数的拷贝**。不像静态库要把静态库代码嵌入自己的程序，动态库被编译后就载入了内存，运行时只要把它映射到程序中，使用相同函数的多个程序同时运行时共享同一份拷贝，节省内存。

- More about DLL
  - DLL for Dynamic-link library，动态链接库，实现共享函数库。动态链接指把一些经常会共用的代码(静态链接的OBJ程序库)制作成DLL档。仅当可执行文件调用到DLL档内的函数时，win操作系统才将DLL加载到存储器内。通过动态链接，存储器的浪费可以大幅度降低。DLL是可执行文件格式，可以包含源代码、数据和资源的多种组合。
  - **在C/C++中DLL的编译将生成DLL和LIB两个文件**。LIB称为输入库(import library)，在编译时为调用DLL的程序提供桩，实际上是间接跳转至运行时载入的DLL的对应函数上再继续执行，这种通过输入库来使用DLL的方式，在程序进行时启动进程时就会自动加载所有用到的DLL。
  - DLL一般来说，必须放在PATH环境变量、缺省系统路径或者使用它的程序所在路径三者之一。
  - VC中允许将C++代码中将函数声明为输入/输出，这种扩展需要在函数声明前使用`__declspec`属性
    - `__declspec(dllexport)`用于在DLL源文件中生命要输出的类、函数以及数据；
    - `__declspec(dllimport)`用于在外部程序声明由DLL输出的C++类、函数及数据

    |             功能              |   windows API    | POSIX API |
    | :---------------------------: | :--------------: | :-------: |
    | 运行时显示调用/运行时动态调用 |  `LoadLibrary `  | `dlopen`  |
    |   查找具有某名称的输出函数    | `GetProcAddress` |  `dlsym`  |
    |            卸载DLL            |  `FreeLibrary`  | `dlclose` |

- 回调函数(callables)：A callable type is a type for which the INVOKE operation（`std::function`,`std::bind`） is applicable,C++17后应该是由`std::invoke`显式调用来实现。
  - C++11中有几种都是*callable*
    - Function pointers
    - std::function objects
    - Lambda expressions
    - bind expressions
    - function objects(classes with overloaded function call operator `operator()`)

- 关于不同的编译器

  - `GCC` 
    - for `GNU Compiler Collection`:被认为是跨平台编译器的事实标准，支持C，C++,Ada, O bjective-C等语言。
    - 实际操作：在用户键入gcc程序名，及命令参数后，gcc便会决定，每个输入文件使用的个别语言编译器，为输出代码选择适合硬件平台的汇编语言编译器，并且选择性地运行linker制造可执行的程序。
    - 每个语言编译器都是独立程序，语言编译器都拥有共同的中介架构:一个**前端**解析匹配此语言的源代码，产生一抽象语法树(Abstract Syntax Tree)，直到最近，程序的语法树尚无法与欲产出的处理器架构脱钩，且语法树的规则有时在不同的语言前端也不同；以及一将此语法树翻译为GCC的寄存器转换语言的**后端**，都包含了标准的最优化方法，如循环最优化，线程跳跃，共通程序子句消减，指令调度等。
  - `Clang`&`LLVM`
    - LLVM
      - for Low Level Virtual Machine，底层虚拟机(后来成长之后LLVM成为众多编译工具以及低级工具技术的统称，这个含义已经被放弃)。是C++写成的一种编译器基础设施，是为了任意一种编程语言而写成的程序，利用虚拟技术创造出编译时期，链接时期，运行时期以及闲置时期的最优化，早期以C/C++为实现对象，目前已支持多种语言。
      - LLVM提供了完整编译系统的中间层，会将中间语言(Intermediate form,IF)从编译器取出与最优化，最优化后被转换及链接到目标平台的汇编语言。
      - 以LLVM作为后端，又有了一些为许多语言开发新的新编译器前端，其中一个就是clang。
    - Clang
      - 是一个C、C++、Objective-C和Objective-C++编程语言的编译器前端，采用了LLVM作为其后端，目标是提供一个GCC的替代品，因此支持了GNU编译器大多数的编译设置及非官方语言的扩展。
