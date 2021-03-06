# 用通配符进行过滤

## 摘要
- 介绍什么是通配符
- 如何在WHERE子句中使用SQL通配符
- 用`LIKE`操作进行通配搜索
- 说明通配符应该细心使用，不能使用过度

## LIKE操作符
以前介绍的搜索条件都是针对已知值进行过滤的，利用通配符可以创建比较特定数据的搜索模式。为在搜索子句中使用通配符，必须使用`LIKE`操作符。

- `LIKE`
  - `LIKE`指示DBMS，后跟的搜索模式利用通配符匹配而不是简单的相等匹配进行比较。
  - **通配符搜索只能用于文本字段(字符串)**，非文本数据类型字段不能使用通配符搜索。

- *通配符(wildcard)*
  - 用来匹配值的一部分的特殊字符;

- *搜索模式(search pattern)*
  - 由字面值、通配符或两者组合构成的搜索条件。
- *谓词(predicate)*
  - 操作符作为谓词时，不是操作符;
  - 技术上来说，LIKE是谓词而不是操作符，虽然结果没什么区别;
  - 应对此术语有所了解。
## 百分号(%)通配符
- `%`
  - 是最常使用的通配符;
  - 搜索串中，`%`表示任何字符出现任意次数(字符出现0次、1次或多次)。
```sql
SELECT prod_name FROM Products WHERE prod_name LIKE 'Fish%';
```
- 说明：Access通配符
  - 如果使用的是Microsoft Access，需要使用`*`而不是`%`。
- 说明：区分大小写
  - 根据DBMS的不同及配置，搜索是可以区分大小写的;
  - MySQL默认不区分大小写。
- 通配符可以在搜索模式中的任意位置使用，并且可以使用多个通配符。
```sql
SELECT prod_id,prod_name
FROM Products
WHERE prod_name
LIKE '%bean bag%';
```
- 提示：根据部分信息搜索电子邮件地址
  - 在用电子邮件地址的一部分查找电子邮件的情况下，把通配符放在搜索模式中间是很有用的。
- 说明：请注意后面所跟的空格
  - 包括Access在内的许多DBMS都用空格来填补字段的内容(因为创建列时规定了字符串长度);
  - 此时如果用`F%y`搜索F开头且y结尾的字符串就会搜索失败，因为后续填充空格，实际上是以空格结尾的，这个时候需要使用搜索模式`F%y%`。
  - 更好的方法是用函数去除后面的空格(RTRIM等)。
- 注意:请注意NULL
  - `%`看起来可以匹配任何字符，但有一个例外，它不能匹配NULL。
### 下划线`_`通配符
- `_`
  - 匹配任意字符(除NULL外)出现1次。
- 说明：DB2通配符
  - DB2不支持通配符`_`。
- 说明：Access通配符
  - 如果使用Microsoft Access，需要使用`?`而不是`_`。
### 方括号`[]`通配符
- `[]`方括号通配符
  - 用来指定一个字符集。
  - 它必须匹配指定位置(通配符所在位置)的一个字符。
- 说明：并不总是支持集合
  - 不同于前面的通配符，并不是所有的DBMS都支持用来创建集合的`[]`。
  - 只有MS的Access和SQL Server支持集合，MySQL不支持。
  - 应该总是参考DBMS的文档。
- `^`脱字号
  - 此前缀`^`可以用来否定`[]`，表示匹配除`[]`内以外的所有字符。
- 说明：Access中的否定集合
  - MS Access中使用`!`而不是`^`来否定集合`[]`。
- `NOT`就可以实现`^`的用途，`^`的唯一优点是可以简化语法。
## 使用通配符的技巧
- 通配符搜索一般比前面讨论的其他搜索条件要耗费更长的处理时间。
- 使用通配符的技巧：
  - 不要过度使用通配符。如果其他操作符也能达到相同目的，应该使用其他操作符;
  - 把通配符置于开始处，搜索起来是最慢的。在确实需要通配符时，也尽量不要把它们放在搜索模式的开始处。
  - 仔细注意通配符的位置。如果放错位置，可能不会得到想要的数据。
