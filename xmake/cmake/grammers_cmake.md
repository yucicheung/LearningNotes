# Basic grammer for cmake
具体指令均应参考`cmake manpage`。
- cmake变量引用一般是`${}`进行变量的引用，在IF等语句中，直接使用变量名而不是通过`${}`取值;
- cmake自定义变量的方式有1.隐式定义;2.显式定义;
  - `<projectname>_BINARY_DIR`/`<projectname_SOURCE_DIR>`就是隐式定义的变量;
  - `SET`用来显式定义。
## 常用变量

