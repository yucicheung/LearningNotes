# 使用函数处理数据

## 摘要
- 介绍如何使用SQL的数据处理函数
- 这些函数在各种SQL实现中很不一致
## 函数
- SQL(与其他计算机语言一样)也可以用函数来处理数据。
- SQL函数所存在的问题：
  - 与几乎所有DBMS都等同支持SQL语句(如`SELECT`)不同，每一个DBMS都有特定的函数;
  - 只有少数几个函数被所有主要的DBMS等同地支持;
  - 虽然所有类型的函数一般都可以在每个DBMS中使用，但是各个函数的名称和语法可能极其不同。
- 举例说明DBMS函数的差异

| 函数 | 语法 |
| --- | --- |
| 提取字符串的组成部分 | Access使用MID();DB2、Oracle、PostgreSQl和SQLite使用SUBSTR();MySQL和SQL Server使用SUBSTRING() |
| 数据类型转换 |　Access和Oracle使用多个函数，每个类型的转换有一个函数；DB2和PostgreSQL使用CAST()；MariaDB、MySQL和SQL Server使用CONVERT() |
| 取当前日期 | Access使用Now();DB2和PostgreSQL使用CURRENT_DATE;MariaDB和MySQL使用CURDATE();Oracle使用SYSDATE;SQL Server使用GETDATE();SQLite使用DATE() |

- 可以看到，与SQL语句不同，SQL函数不是可移植的。
- *可移植(portable)*
  - 所编写的代码可以在多个系统上运行。
- 提示：是否应该使用函数
  - 如果使用函数，应该保证做好代码注释,以便以后的读者可以确切地知道编写的SQL代码的含义。
## 使用函数
- 大多SQL实现支持以下类型的函数：
  - 用于处理文本字符串（如删除或填充值，转换为大写或小写）的文本函数;
  - 用于在数值数据上进行算数操作（如返回绝对值，进行代数运算）的数值函数;
  - 用于处理日期和时间值并从这些值中提取特定成分（如返回两个日期之差，检查日期有效性）的日期和时间函数;
  - 返回DBMS正使用的特殊信息（如返回用户登录信息）的系统函数。
### 文本处理函数
- 常用的文本处理函数(对MySQL全部适用)

| 函数 | 说明 |
| --- | --- |
| LEFT()（或使用子字符串函数） | 返回字符串左边的字符 |
| LENGTH()（也使用DATELENGTH()或LENGTH()） | 返回字符串的长度 |
| LOWER()（Access使用LCASE()） | 将字符串转换为小写 |
| LTRIM() | 去掉字符串左边的空格 |
| RIGHT()（或使用子字符串函数） | 返回字符串右边的字符 |
| RTRIM() | 去掉字符串右边的空格 |
| SOUNDEX() | 返回字符串的SOUNDEX值 |
| UPPER()（Access使用UCASE()） | 将字符串转换为大写 |

- `SOUNDEX`：是一个将任何文本串转换为描述其语音表示的字母数字模式的算法;
  - `SOUNDEX`考虑了类似的发音字符和音节，使得能对字符串进行发音比较而不是字母比较;
  - `SOUNDEX`虽然不是SQL概念，但多数DBMS都提供对`SOUNDEX`的支持。
- 说明：SOUNDEX支持
  - MS Access和PostgreSQL不支持SOUNDEX()。
  - `SQLite`是否支持SOUNDEX由编译时的选项决定，并不是默认功能。
```sql
SELECT cust_name, cust_contact
FROM Customers
WHERE SOUNDEX(cust_contact) = SOUNDEX('Michael Green');
```
### 日期和时间处理函数
- 日期和时间采用相应的数据类型存储在表中，每种DBMS都有自己的特殊形式。
  - 日期和时间以特殊格式存储，以便能快速和有效地排序或过滤，并且节省物理存储空间。
- 日期和时间函数
  - 应用程序一般不使用日期和时间的存储格式，因此日期、时间函数总是用于读取、统计和处理这些值，日期和时间函数也由此在SQL中具有重要作用;
  - 遗憾的是，它们的可移植性最差。
- 用于检索order_date年份为2012的行,以下用于提取年份：

| DBMS | 函数 |
| --- | --- | 
| SQL Server | DATEPART(yy,order_date)=2012 |
| Access | DATEPART('yyyy',order_date)=2012 |
| PostgreSQL | DATE_PART('year',order_date)=2012 |
| Oracle | to_number(to_char(order_date,'YYYY'))=2012或order_date BETWEEN to_date('01-01-2012') AND to_date('12-31-2012') |
| MySQL/MariaDB | YEAR(order_date)=2012 |
| SQLite | strftime('%Y', order_date)='2012' |

```sql
-- 在MySQL中的实现
SELECT order_num
FROM Orders
WHERE YEAR(order_date) = 2012;
```
- 大多数DBMS具有比较日期、执行基于日期的计算、选择日期格式等的函数，具体的支持应参阅相应文档。

### 数值处理函数
- 一般主要用于代数、三角或几何运算，因此不像字符串和日期-时间处理函数使用那么频繁。
- 讽刺的是，在主要DBMS上，数值函数是最一致、最统一的函数。

| 函数 | 说明 |
| --- | --- |
| ABS() | 返回一个数的绝对值 |
| COS() | 返回一个角度的余弦 |
| EXP() | 返回一个数的自然级数 |
| PI() | 返回圆周率 |
| SIN() | 返回一个角度的正弦(弧度) |
| SQRT() | 返回一个数的平方根 |
| TAN() | 返回一个角度的正切(弧度) |
