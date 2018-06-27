# Matlab复杂功能创建

- `whos`查看所有变量占用字节数和类型，`whos var`查看某个变量所占字节数和类型。
- 不管是`struct`还是`cell`，都比单纯的同类型矩阵占用内存大得多。
  - 一个是上述类型需要额外的空间存储结构本身的信息。
  - 如果改为由单个矩阵数据的存储，会占据很少的存储量。举个例子，矩阵单独存取占据的空间可能是169M，而转化成struct之后存储空间需要占据2G以上。可能是由于在存储时struc会自动把数据转化为double类型，从而导致最终尺寸扩大若干倍。
- `.mat`格式本身是对数据有压缩作用的。
- `%%`后跟随的叫做*代码节*。这样可以只运行一部分，在单独的代码节中进行单节调试和运行，查看每一段的运行情况。
- 字符数组`''`围起，字符串`""`围起，在文件名函数中一般只支持字符数组输入。
- Matlab函数参数传递方式是传值方式，但是不一定产生复制，只有在输入参数被修改时才有可能发生复制，即所谓的`Copy-on-write`.

## 可视化篇
- `imwrite`图片写出
  - 存储图片时，除非要存储的本身就是二值图， 否则需要将其做归一化后再进行存储。

- `imshow`图片显示
  - 对于输入的图片矩阵一般会自动进行归一化， 然后做显示；
  - 要显示多幅图片，用subplot会将画面压缩得过小，因此或者多开一个画布figure()轮流控制画布显示图片，或者将图片拼接之后做imshow(此时要保证图片都是同一类型， 如都做了归一化)。
  - 对于过大的图片，用imshow做显示时，其内部机制会自动缩放图片以适应屏幕。

- `scatter3`三维散点图
  -  
  - 相关函数

| 函数名 | 功能说明 |
| --- | --- |
| `scatter3(X,Y,Z)` | 在向量X、Y、Z的指定位置显示圆圈 |
| `scatter3(X,Y,Z,S)` | 使用S指定的大小绘制每个圆圈。<br>s为标量，则圆圈相同；<br>s为向量，则每个圆有自身特定大小 |
| `scatter(X,Y,Z,S,C)` | 其中C指定每个圆圈的颜色。<br>C是RGB三元数，或是包含颜色名，则用指定颜色绘制圆圈。<br>C是三列矩阵，其中C中的行数等于X、Y和Z的长度，则C的每行指定相应圆圈的RGB值。<br>C是长度与X、Y、Z的长度相同的向量，C中的值线性映射到当前颜色图中的颜色。 |
| `scatter3(__,markertype)` | 指定标记类型 |
| `scatter3(__,Name,Value)` | 使用一个或多个名称-值对组参数修改散点图 |
| `scatter3(ax,__)` | 将图形绘制到ax指定的坐标区中，而不是当前坐标区(gca)中。<br>选项ax可以位于前面的语法中的任何输入参数组合之前<br>具体说来是选择在不同的图像区域进行作图 |
| `h=scatter3(__)` | 返回Scatter对象，在创建散点图后，用h修改其属性 |

##数据结构
### 结构体

- 直接引用方式定义结构
  - 与建立数值型数组一样，建立新struct对象不需是事前声明，可以直接引用，并且可以动态扩充(尺寸或者字段)。
  - 其中每个字段可以是任意的数据类型，可以是向量、数组、矩阵或者是其他结构变量或元胞数组，且不同字段之间的数据类型不需一致。
  - 甚至不同元素的同一字段的数据类型也不要求一致。

```matlab
% 建立新对象
x.real = 0;
x.imag = 0;
% 动态扩充数组为1x2的结构数组
x(2).real = 0;
x(2).imag = 0;
% 动态增加字段scale
x(1).scale = 0;%会使所有x都增加一个scale字段，未定义的scale字段为空
```

- 使用struct函数创建结构
  - 函数把其他形式的数据转换为结构数组
  - 使用格式`s=struct('field',value1,'field2',value2,...);`
  - 这种情况下，函数将生成一个有指定字段名和相应数据的结构数组，每一个字段的数据类型是确定（统一）的。
  - **要求每一个field都有一样的维度**；
  - 如果任意一个field用cell定义，最终struct的尺寸就会和cell一样，否则struct的尺寸就是1x1。

```matlab
s=struct('type',{'big','little'},'color',{'blue','red'},'x',{3,4})
```

- 结构体操作函数

| 函数名 | 功能描述         | 函数名 | 功能描述 |
| :------: | :----------------: | :------: | :--------: |
| deal   | 把输入处理成输出 | fieldnames       |   获取结构体数组的字段名    |
| getfield | 获取结构体数组中指定字段的值 | rmfield | 删除结构体数组的字段 |
| setfield | 设置结构体数组中指定字段的值| struct | 创建结构体数组 |
| struct2cell | 结构体数组转换为元胞数组 | isfield | 判断是否存在该字段 |
| isstruct | 判断该变量是否是结构体数组类型 | | |

### 元胞数组
- 元胞数组
  - 我认为的cell主要是一个placeholder的功能。定义同时分配值是其中的一种选择而已。
    - cell中每个位置都可以是不同的类型，甚至可以是结构体，这样就增加了它的灵活性(说来这种灵活性主要是来自于结构体而非cell类型)。
    - 用`{}`进行元胞数组的定义，也用`{}`进行元胞数组的取值，用`[]`进行数组的索引显示其类型。
  - 可以使用cell预分配一个元胞数组，稍后在为其分配数据。
  - cell还可以将某些类型的java、.NET和Python数据结构体转换为由等效的MATLAB对象组成的元胞数组
  - 一些函数如下
| 函数名 | 功能 |
| :---: | :----: |
| `cell(n)` | 返回由空矩阵构成的nxn元胞数组 |
| `cell(sz1,...,szN)` | 返回由空矩阵构成的sz1x...xszN元胞数组 |
| `cell(sz)` | 返回由尺寸向量定义大小的元胞数组 |
| `cell(obj)` | 可以将Java数组、.NET System.String或System.Object数组、Python列表转换为元胞数组 |

```matlab
c={1,2,3;'text',rand(5,10,2),{11; 22; 33}}% 创建一个2x3的cell array
c={};% 创建一个0x0的元胞数组

```

## 方法
### 函数

- 函数句柄
  - 基本定义
    - 用于间接调用函数的变量，用于存储函数关联项的数据类型。
    - 间接调用函数使调用函数时无需考虑调用位置。
  - 典型用法
	- 可以为已命名函数和匿名函数创建函数句柄；
	- 可以将多个函数句柄存储在数组中，保存并加载它们；
	- 
    - 可以使用函数句柄构造匿函数或回调函数。
    - 也可以使用函数句柄将一个函数传递给另一个函数，或者从主函数外部调用局部函数。
  - 函数句柄创建
    - 函数句柄

- 输入输出参数个数
  - 输入参数个数`nargin`
	- `nargin`针对当前正在执行的函数，返回函数调用时输入的参数个数，仅在函数体内可用。
		 `nargin(fun)`返回函数fun定义中出现的输入参数的数目，如果该函数定义中包含varargin，那么nargin返回输入数目的负数。如`function varargout=myFun(a,b,varargin)`，返回值为-3。 	
  - 输入参数个数`nargout` 

- 验证输入参数数目
  - `narginchk(minArgs,maxArgs)`(边界包含)
  - 验证当前执行的函数调用中的输入参数数目。如果调用中的指定数目小于minArgs或大于maxArgs，narginchk将引发错误；
  - 只有最小数目限制，没有最大数目限制，设为`narginchk(minArgs,inf)`
  - 验证参数数目为一个确切值，设为`narginchk(minArgs,minArgs)`

- 可变长度输入参数列表`varargin`
  - 是函数定义语句中的一个输入变量，允许函数接受任意数量的输入参数。使用小写字符指定varargin，将其作为左后一个输入参数附加在任何显式声明的输入项后。在执行函数时，varargin是一个1xN的元胞数组，其中N是函数在显式声明的输入后收到的输入项数(如果显示声明输入后未收到任何输入，则varargin是空元胞数组)。
```matlab
% 个数不定的函数输入项
function acceptVariableNumInputs(varargin)
	disp("Num of input args:"+nargin)
	celldisp(varargin)
end
% 显式声明的输入项和varargin
function definedAndVariableNumInputs(X,Y,varargin)
	disp("Total number of input arguments:"+nargin)
	
	formatSpec="Size of varargin cell array: %dx%d";
	str=compose(formatSpec,size(varargin));
	disp(str)
end
% 可变数目的输入和输出
function varargout = variableNumInputAndOutput(varargin)
	disp(['Number of provided inputs:' num2str(length(varargin))])
	disp(['Number of requested outputs:' num2str(length(nargout))])
	
	for k = 1:nargout
		varargout{k}=k;
	end
end
% 创建函数封装程序
function varargout = redplot(varargin)
	[varargout{1:nargout}] = plot(varargin{:},'Color',[1,0,0]);
end
```

- 可变长度的输出参数列表`varargout`
  - 函数定义语句中的一个输出变量，允许函数返回任意数量的输出参数。
  - 使用小写字符指定`varargout`，将其作为最后一个输出参数附加在任何显式声明的输出后，执行函数时，varargout是一个1XN元胞数组，其中N是显式声明的输出结果后请求的输出数量。
```matlab
% 个数不定的函数输出项
function [s,varargout] = returnVariableNumOutputs(x)
```


## 异常处理
- [异常的基本信息](https://ww2.mathworks.cn/help/matlab/matlab_prog/capture-information-about-errors.html)
  - 检测错误并引发异常的任何代码必须构造一个MException对象，在该对象中记录并传输有关错误信息，MException构造函数的语法为`ME=MException(identifier,message)`
	- `identifier`是在单引号中的一个MATLAB消息标识符；
	- `message`是一个文本，仍在单引号中，描述错误；
	- `ME`返回值是一个MException对象。
  - `MException`类的四个属性：每个属性都是以表示MException对象的结构体的一个字段的形式来实现的。所有属性都是只读，而不能更改其值。
    - `identifier`：消息标识符，是一个附加到错误或警告语句的标记，使错误或警告可以由MATLAB唯一识别。消息标识符使一个只读字符向量，用于指定 错误或警告的组建和助记键标签，简单标识符的格式为component:mnemonic，如`MATLAB:rmpath:DirNotFound`,`TechCorp:OpenFile:notFoundInPath`.
    - `message`
    - `stack`
    - `cause`

- 捕获异常
  - 捕获异常用`try-catch`语句进行，异常捕获后可以看到MException对象结构体的四个属性。
```matlab
try
	surf
catch ME
	ME
end
```

- [引发异常](https://ww2.mathworks.cn/help/matlab/matlab_prog/throw-an-exception.html)
  - 当程序检测到阻止程序完成的故障时，应当通过引发异常停止进一步执行并报告错误。


  - 参考步骤如下
```matlab
% 1 Detect the error
try
	A(idx);
catch
	% 2 Construct an MException object to represent the error
	msdID = 'MYFUN:BadIndex';
	msg = 'Unable to index into array';
	baseException = MException(msgID,msg);
	
	% 3 Store any information contributing to the 
```

## 高级开发
### matlab与python的混合编程

- 什么时候使用
  - 既要利用matlab方便的矩阵运算，又要利用python的独有特性(list/dict)或丰富的第三方包( 比如OpenCV)时，就可以采用这种编程方式。

- From matlab calling python(具体参考官方文档)
  - Matlab支持CPython的参考实现，在Mac或者Linux下默认安装有python，但是在win下，需要安装分发版的python。
  - `help py`查看函数引擎接口。
  - 调用包用成员符号`.`完成。举个例子`T="I am exhausted.";words = py.textwrap.wrap(T);`
  - 调用自定义函数/文件
	- 也是和调用库函数一致(毕竟库本身也是一些文件的集合)，比如有一个`test.py`文件，其中计算了一个c值，运行它可以用命令`py.test1.c`；
	- 或者`import py.test.*`;

| 函数名    | 功能                   |
| --------- | ---------------------- |
| `pyversion` | 从matlab检测python版本 |


- From Python calling matlab(具体参考官方文档)
  - 安装
	- 进入MATLAB安装文件目录中`extern\engines\python`，输入`Python.exe setup.py install`（用管理员身份运行）。
	- 输入`import matlab`测试环境是否配置成功 
  - 启动引擎
	- 如下举个例子，说明在Python中启动`matlab`引擎和引用函数计算
```python
import matlab.engine
eng = matlab.engine.start_matlab()% takes a long time
tf = eng.isprime(37)
```

### Matlab与C++的混合编程

- Calling Matlab from C++

### Matlab Coder自动输出为其他语言源代码



### Matlab的矩阵运算加速方法
- MKL库from Intel
