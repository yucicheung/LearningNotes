## 如何决定一个class对象的尺寸

C++中影响一个类对象的尺寸的因素，有：
1. 非static数据成员的尺寸
2. 数据成员的顺序
3. 字节对齐/字节补丁
4. 直接基类的尺寸
5. 虚函数的存在
6. 使用的编译器
7. 继承的模式(虚拟继承)


### 含有非静态成员
只有非static成员才会被计算到class/object的尺寸中
```
class A{
private:
	float iMem1;// 4 bytes
	const int iMem2;// 4 bytes
	static int iMem3;
	char iMem4;// 1 bytes
};

printf("%d",sizeof(A));//12，仍然内存对齐？
```

### 内存对齐
内存对齐一般是为了提高程序的性能，数据结构(栈)应该给尽可能在自然边界上对齐，因为访问未对齐内存时，需要做两次内存访问，对齐内存只需要做一次访问，即“内存对齐”应是编译器的管辖范围，非常依赖平台。
- char,偏移量必须为sizeof(char)即1的倍数
- int,偏移量为sizeof(int)，4的倍数
- float，偏移量为4的倍数
- double,偏移量为8的倍数
- short，偏移量为2的倍数
另外，为了确保结构大小为结构的字节边界数(结构体中占用最大空间类型占用的字节数)的倍数，所以为最后一个成员申请空间后，会根据需要自动填充空缺的字节。

#### 如何关闭内存对齐
- 对整个文件关闭内存对齐，使用预处理指令`#pragma pack(1)`使内存按照一个字节对齐。
```c++
#pragma pack(1)
struct A_{
	int a;
	int b;
	char c;
};
```
- 使用`__attribute__((packed))`对其中某个/某几个结构体关闭内存对齐。
```c++
struct B_{
	int a;
	int b;
	char c;	
}___attribute__((packed));

```

