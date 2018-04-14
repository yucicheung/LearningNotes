# python Debug笔记
- 当类的内部函数调用时，必须保持被调用的函数在调用方之前已定义。

- `tqdm`用于显示目前程序运行进度的程序包。
- `global`变量用于改变在函数外定义的变量时使用，声明在子函数的开头。

- 嵌套函数的内部函数中使用`global`声明变量并不能修改外层变量的值，但是外层函数定义的值，内部可直接调用。

- tkinter中，
  - 关于布局：
	- `grid`和`pack`不能混用;
	- `grid`和`place`可以一起用。
  - 关于messagebox：
	- 应直接`import tkinter.messagebox`。
  - 设置变量时目前使用的有：
	- `tk.StringVar()`;
	- `tk.IntVar()`。
  - 关于图片显示：
	- 用`tk.Label()`显示(规定好size，如width和height);
	- label应该先固定好;
	- 要改变图片显示时，读取图片内容`Image.open()`，再用`ImageTk.PhotoImage()`变为tkinter支持格式，最后将label的img和label['img']值设置为tkinter支持内容。

- 查看已安装包(pip)的信息，如查找不到可能是通过`apt`安装，此时可以通过`dpkg -l`+`grep`查找并查看相关信息：
  - `pip list`
  - `pip freeze`
