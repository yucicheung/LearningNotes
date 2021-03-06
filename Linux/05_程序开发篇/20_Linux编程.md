# Linux编程
- C是Linux下最常用的编程语言，Linux本身就是C写的。
- 最常用的编辑器是Vim和Emacs。
- vim是ubuntu下默认配置而emacs不是，着重介绍Vim编辑器。
- 介绍C和C++程序的编译运行。
## Vim编辑器
- Vim是Vi的增强版本，在不正式的情况下，两者是一回事。
- Vim是所有UNIX和Linux系统下的标准软件。
### 两种模式/编辑和保存
- `vim file`:对文件用vim编辑器进行编辑。如果文件不存在，Vim将自动创建文件。
   - `vim` : 不带参数的vim自动打开编辑器。
- vim分为*插入*和*命令*两种模式。Vim启动时自动处于命令模式。
  - 按'I'键进入插入模式，此模式下可以输入字符;
  - 按'Esc'键进入命令模式，此模式下执行除了字符操作以外的所有操作，包括保存、搜索、移动光标等。
- 命令模式下，输入“：”在底部打开一个命令行，此时光标闪烁输入，等待用户输入。
- H、J、K、L分别代表向左、上、下、右移动。当然使用方向键也是可以的。
- O在当前行下插入一行空白行。
- `w`保存，`q`退出，`wq`保存且退出，`q!`强制退出。
### 搜索字符串
- `/string`用于搜索一个字符串，输入`/`后，vim底部也会出现一个命令行。
- vim的搜索可以循环进行，`/`命令向前(文件尾)查找，`？`命令向后(向文件头)查找。
- 对大小写是否敏感：
  - `:set ignorecase`命令vim忽略大小写;
  - `:set noignorecase`命令vim重新开启大小写敏感。
### 替换字符串
- `:[range]s/pattern/string/[c,e,g,i]`:替换命令的完整语法，将匹配pattern(正则表达式)的字符串替换为string。
  - range规定替换范围，`1,4`表示1到4行，`1,$`表示1行到最后一行(全文)，`%`也表示全文。
  - 最后方括号内的字符是可选选项，选项含义如下：

	| 标志 | 含义 |
	| --- | --- |
	| c | 每次替换前询问 |
	| e | 不显示错误信息 |
	| g | 替换一行中的所有匹配项（通常需要使用,否则替换第一项） |
	| i | 不区分大小写 |

- \*清除文本文件中的`^M`字符：由于来自windows环境的源代码对换行符的表述和Linux不一致，因此文末常出现`^M`符号——虽然对程序编译器和解释器没有影响，但在shell编程时会产生问题，此时用`%s/^M$//g`删除行末的`^M`字符。
### 针对程序员的配置
- 一些常用的配置命令：
  - `:syntax on`打开语法高亮，vim会根据文件扩展名决定哪些为关键字。
  - `:set autoindent`设置自动缩进;
  - `:set shiftwidth=4`设置自动缩进的空白长度;
  - `:set tabstop=4`将tab键缩进设置为4个空格。
- 为避免每次启动vim都要手动输入命令，可以将命令写入vim的配置文件中(文件中不要包含`:`)，vim的配置文件为`/etc/vim/vimrc`(/etc中的文件对系统中所有用户生效)，推荐用户可以新建一个`~/.vimrc`文件在其中写入配置信息，只对当前用户生效。
  - **通常用户个性化的设置文件都是隐藏文件(`.`开头的文件)，且保存在用户主目录下**。
### Vim的常用命令总结
- 模式切换：
  - `a`:在光标后插入;
  - `i`:在光标所在位置插入;
  - `o`：在光标所在位置下一行插入;
  - `Esc`:进入命令模式;
  - `:`进入行命令模式。
- 光标移动(名列前加上数字，可以重复多次移动，如`5w`)：
  - `h`/`l`/`j`/`k`：光标向左/右/上/下移动;
  - `^`/`$`：移动光标到行首/尾;
  - `gg`/`shift+g`:移动光标到文件首/尾;
  - `w`/`b`:移动到下一个/上一个单词;
  - `ctrl+f`/`ctrl+b`:向前(文件尾)/后(文件头)翻动一页。
- 删除、复制和粘贴：
  - `x`:删除光标所在位置的字符;
  - `dd`：删除光标所在行;
  - `shift+d`:删除光标所在位置到行尾的所有字符;
  - `d`:和移动命令配合使用的删除命令，如`dw`表示删除光标所在位置到下一个单词之间的所有字符;
  - `yy`:复制光标所在行;
  - `y`:和移动命令配合使用的复制命令;
  - `shift+p`:在光标所在位置粘贴最近复制/删除的内容。
- 撤销和重做：
  - `u`：撤销一次操作;
  - `ctrl+r`:重做被撤销的操作。
- 搜索和替换：
  - `:/string`：向前搜索字符串string;
  - `:?string`：向后搜索字符串string;
  - `:s/pattern/string`：将pattern代表的字符串替换成string。
- 保存和退出：
  - `:w`：保存文件;
  - `:w filename`：另存为filename;
  - `:q`：退出vim;
  - `:!q`：强制退出，放弃保存修改。
## C/C++的编译(gcc/g++)
- gcc最初是C编译器(GNU C Compiler)，如今支持多种语言编译(GNU Compiler Collection)。
- `gcc *.c`:编译C源文件，默认产生一个可执行文件为`a.out`;
  - `gcc -o <outname> *.c`:指定产生的可执行文件名字为`outname`。
- 和编译有关的选项：
  - `-c`：只激活预处理、编译和汇编，生成扩展名为.o的目标代码文件(在编写大型程序时必须，存在依赖关系的源代码应首先编译成目标代码，最后连接成可执行文件，超过3个源文件考虑用`make`);
  - `-S`：只激活预处理和编译，并生成扩展名为.s的汇编代码文件;
  - `-E`：只激活预处理，并将结果输出至标准输出;
  - `-g`：为调试程序(gdb)生成相关信息。
- 优化选项：gcc提供了从低到高3个级别的优化选项，依次为`-O1`、`-O2`、`-O3`。
  - 优化程序越高，效率越高，相应风险越大;
  - 通常`-O2`选项可以满足绝大多数优化需求;
  - 这三个优化级别其实就是对多个优化选项的“打包”。
- `-march=`生成只适合特定CPU的二进制代码(一般不使用)。
- `g++ *.cpp`：用g++完成C++程序的编译和连接(`gcc`可以编译C++源文件，但不能和C++程序使用的库连接)，会自动调用`gcc`完成对文件的编译;
  - `-o`：同`gcc`，此选项指定可执行文件名。
## C程序的调试(gdb)
- 使用`gdb`调试C/C++程序之前，要先使用`gcc -g`生成带有调试信息的可执行程序，否则只有汇编代码存在。
- `gdb a.out`：gdb以可执行二进制文件为参数，对其进行调试，运行后显示提示符(gdb)等待接受用户指令;一些常用指令如下：
  - `help`/`help <command>`：获取(和特定命令)有关的帮助信息;
  - 支持<tab>命令补全，当不足以确定唯一命令时，连按两次tab获得所有符合要求的命令;
  - 支持命令缩写，如`h`就可以替代`help`;
  - `list`/`l`:用于查看程序源代码(会自动在源代码前加上行号，每次显示10行，可指定中间行);
  - `search <content>`：搜索特定内容，只能向前搜索，不能循环，支持正则表达式;
  - `reverse-search <content>`：反向搜索特定内容，向后搜索，支持正则表达式。
- 断点指令：
  - `break`/`b`：在指定位置设置断点，可以用行号或函数名做参数;
  - `info break`：查看已设置断点信息;
  - `clear`：清除当前行断点。
- 运行程序和单步执行：
  - `run`/`r`：运行程序至断点;
  - `next`/`n`：单步执行程序，可在后面添加数字n，表**连续执行n行**;
  - `step`/`s`：单步执行，会在遇见函数时进入函数内部，而`n`只执行调用函数不进入内部;
  - `continue`/`c`：继续运行程序直至遇见下一个断点;
- 监视变量：
  - `print`/`p`：打印指定变量的值;
  - `watch`/`w`：设置观察点(可以看作是变量的一种)，以变量名/表达式为参数，一旦参数值发生变化，就停下程序。
- 临时修改变量：
  - `set var`实现，如`set var i=1`
- 查看堆栈情况(每次程序调用一个函数，其地址、参数、函数内的局部变量都会被压入栈中)：
  - `bt`实现。
- 退出gdb：
  - `quit`/`q`。
## 版本控制系统
- 不论是与他人协作还是管理自己的密码，版本控制系统(git和SVN)都是非常好的工具。
- 版本控制系统是一套在开发程序时存储源代码所有修改的工具。满足这些需求：
  - 集中化管理，自动跟踪单个文件的修改历史;
  - 完善的日志机制，便于掌握某次修改的原因;
  - 快速还原到指定的版本;
  - 协调不同开发者之间的活动，保证对源代码同一部分的改动步互相覆盖。
- Subversion相比git，管理人员对开发人员的权利可以作出规范，但git是最好用的版本管理工具。
- git的使用，可以参考我的其他笔记。
