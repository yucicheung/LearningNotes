# vector
使用数组初始化vecotr对象，只要知名要拷贝区域的首元素地址和尾后地址就可以了。
```c++
int int_arr[]={0,1,2,3,4,5};
vector<int> ivec(begin(int_arr),end(int_arr));
```
当然，用来初始化vector对象的值也可能仅是数组的一部分。
```c++
vector<int> subVec(int_arr+1,int_arr+4);
```

**建议**：尽量使用标准库类型而非数组。

## 关于迭代器的说明
- 迭代器
  - 一般容器类型都有自置的成员函数begin和end，返回指向首元素的迭代器和尾后迭代器；
  - 就像不知道string和vector的size_type成员到底是什么类型，一般我们也不知道(其实是无需知道)迭代器的精确类型，所以一般使用`auto`获取迭代器的准确类型，如`auto it=s.begin();`。
  - c11标准中出现了`cbegin`和`cend`函数返回const_iterator。

- 迭代器类型
  - const_iterator：只能读元素，不能写元素，如果对象是常量，则begin和end返回的就是常量迭代器。
  - iterator：能读也能写元素，如果对象不是常量，begin/end返回的就是iterator。

- 标准库函数begin和end(c11标准引入)
  - 使用数组作为参数，begin返回首元素的指针，end函数返回指向尾元素下一元素的指针，两个函数定义在'iterator.h'中
  - 以下举例用begin和end进行arr中的循环。
```c++
int ia[1000]={1,};
auto pbeg= begin(ia);
auto plast= end(ia);
while(pbeg!=plast&&(*pbeg)){cout<<*pbeg<<endl;++pbeg;}
return 0;

```

