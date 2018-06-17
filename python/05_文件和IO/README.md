#文件IO
## 二进制文件IO
### 概念
- 二进制文件的读写与普通文件读写差别在于，普通文件中存储的是ASCII码，而二进制文件中存储的是字节串(byte string)。就比如说`123`这个数字，在普通文件中存储的分别是`1`,`2`,`3`三者的ASCII码值(各占1个字节)，而二进制存储时，只用占据一个字节就能存储该数字(123<255)。
  - 当对二进制文件进行写入时，数据必须直接以字节码形式暴露出来(字节串、bytearray对象等)。
### 读写
- 直接读取二进制文件
```python
with open('somefile.bin','rb') as f:
	data = f.read()
with open('somefile.bin','wb') as f:
	f.write(b'Hello world!')
```

- 如果要对二进制文件**读写文本数据**，必须进行**编码解码操作**。再次强调，这种方法只适用于**与二进制文件进行文本数据的交互**。
```python
#用open()的rb或wb模式实现二进制文件的IO
with open('somefile.bin','rb') as f:
	data = f.read(16)
	text = data.decode('utf-8')
with open('somefile.bin','wb') as f:
	text = b'Hello World!'
	f.write(text.encode('utf-8'))

```
- 关于二进制I/O，对于某些**实现了"缓冲区接口(buffer interface)"的对象**，可以直接将对象底层的缓冲区暴露给上层可以进行的操作，而不用进行转化为byte对象。比如，C结构体和数组这类对象。**但是要特别小心这种操作是依赖于平台特性的，也依赖于字(word)的大小和字节序(即大端和小端)等属性**。
  - **(可以这么理解，对于这些实现了缓冲区接口的对象，它对文件的读写函数都已经做好了重载，可以随时用作显示)**;
  - 对二进制文件的**写**，用`f.write()`从内存直接写入到底层中;
  - 对二进制文件的**读**，直接将二进制数据读入到底层的内存中，利用文件对象的`readinto()`方法即可。
```python
# 用array对象直接对二进制文件的写
import array
nums = array.array('i',[1,2,3,4])
with open('data.bin','wb') as f:
	f.write(nums)

# 对二进制文件的读
import array
a = array.array('i',[0,0,0,0,0,0,0,0])
with open('data.bin','rb') as f:
	f.readinto(a)
a # array('i',[1,2,3,4,0,0,0,0])
```

- 相较于文本文件中常见的按行迭代文件对象，**对于二进制文件还是按照固定大小**的记录/数据块进行**迭代**比较适用。利用`iter()`和`functools.partial()`可以完成这个技巧。但是文件读取后是通过str格式显示的。
```python
from functools import partial

RECORD_SIZE = 32
filename = 'data.bin'
with open(filename,'rb') as f:
	records = iter(partial(f.read,RECORD_SIZE),'end of file')
	for r in records:
		...
```

- 对于二进制数据，因为要可能要根据不同位数读取数据(如16位,32位,64位)，因此这种情况下，选择1.既能将底层缓冲区暴露给上层操作,2.又直接实现了对缓冲区进行不同长度数据读取函数,的对象会是最好的选择。就比如我们可以选择numpy里面利用`dtype`做数值类型转换。


