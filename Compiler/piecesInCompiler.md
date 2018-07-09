# piecies notes in compiler

## [release和debug模式的差别](https://www.zhihu.com/question/37109507)
通常主要的区别有两个
1. debug的代码不会优化(最大程序降低给debugger带来的麻烦)。
2. debug的代码会插入大量的检查，帮助更早发现问题(譬如数组溢出等：填充rep指令防止缓冲区溢出或者数组越界)，还能在运行真值时中断下来(这其实是第一点，因为被优化掉了)。
