# Pieces of knowledge

## CMake简介
- 其他常见Make工具及主要劣势
  - 常见Make工具
	- GNU的`Make`
	- QT的`qmake`
	- Microsoft的`nmake`
	- BSD的`pmake`
  - 主要劣势：**软件的跨平台性差**。要保证在不同平台编译，如果用以上Make工具就必须用每一种标准写一Makefile。
	- Make工具遵循不同的规范和标准;
	- 执行的Makefile格式也千差万别。
- `CMake`及其优势
  - `CMake`允许开发者编写一种平台无关的的CMakeList.txt文件来定制整个编译流程，然后再根据目标用户平台进一步生成所需的本地化Makefile和工程文件，如UNix的Makefile或Windows的VS工程，从而做到‘wrote once,run everywhere’，因此CMake是一个比上述Make更高级的编译配置工具。

- Linux下使用CMake生成Makefile并编译的流程如下
  1. 编写CMake配置文件CMakeLists.txt;
  2. 执行命令`cmake PATH`或者`ccmake PATH`生成Makefile，其中`PATH`是CMakeLists.txt所在目录;
  3. 使用`make`命令进行编译。

## 源文件编译实例
- 单个源文件项目编译实例(文件结构如下)
  - 编写`cpp`文件。
  - 编写`CMakeLists.txt`文件，保存在与`cpp`源文件同目录下。`CMakeLists.txt`语法较为简单，由命令、注释和空格组成：其中命令不区分大小写，符号`#`后接着注释，命令由命令名称、小括号和参数组成，参数之间用空格进行间隔。
  - 编译项目
	1. 在当前目录执行`cmake .`得到Makefile;
	2. 得到Makefile后使用`make`命令编译得到`Demo`可执行文件;

```txt
./Demo1
  	|
	+--- main.cc

# CMake最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo1)

# 指定生成目标
add_executable(Demo main.cpp) #将名为`main.cpp`的源文件编译成一个名称为Demo的可执行文件

```

- 同一目录，多个源文件编译实例(文件结构如下)

```txt
./Demo2
	|
	+--- main.cc
	|
	+--- MathFunctions.cc
	|
	+--- MathFunctions.h

# CMake最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project　(Demo2)

# 指定生成目标
## 方法1
##		1.源文件很少时直接将cc文件添加到add_executable函数中作为参数
add_executable(Demo main.cc MathFunctions.cc)
## 方法2
##		1.源文件很多时，使用命令直接查找指定目录下的所有源文件，将名称存入指定变量名
aux_source_directory(. DIR_SRCS) #aux_source_directory(<dir> <variable>)
##		2.指定生成目标
add_executale(Demo ${DIR_SRCS})

```

- 多个目录，多个源文件编译实例(文件结构如下)
  - 在项目根目录Demo和math目录中各编写一个CMakeLists.txt文件。为方便，可以先将math目录里的文件编译成静态库再由main函数调用。

```txt
./Demo3
	|
	+--- main.cc
	|
	+--- math/
			|
			+--- MathFunctions.cc
			|
			+--- MathFunctions.h
#############根目录中的CMakeLists.txt#############
# CMake最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (Demo3)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量中
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
add_subdirectory(math) # 在执行此命令时进入子目录进行子目录中的CMakeLists.txt执行， 变量查找，链接库生成

# 指定生成目标
add_executable(Demo main.cc)

# 添加链接库
target_link_libraries(Demo MathFunctions) # 为可执行文件Demo添加链接库

#############子目录中的CMakeLists.txt#############
# 查找当前目录下的所有源文件，并将名称保存到`DIR_LIB_SRCS`变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(MathFunctions ${DIR_LIB_SRCS}) # 将src目录中的源文件编译为静态链接库LIB
```

## 自定义编译实例
- CMake允许为项目增加编译选项，从而可以根据用户的环境和需求选择最合适的编译方案。
  - 以下将MathFunctions设置为一个可选的库，如果该选项为`ON`，就使用该库定义的数学函数进行运算，否则使用标准哭中的数学函数库。

```txt
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)
# 是否使用自己的 MathFunctions 库
option (USE_MYMATH
		"Use provided math implementation" ON)

# 是否加入 MathFunctions 库
if (USE_MYMATH)

```
