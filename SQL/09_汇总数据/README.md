# 汇总数据

## 摘要
- 什么是SQL的聚集函数
- 如何使用聚集函数汇总表的数据
- SQL支持5个聚集函数，可以用多种方法使用它们，返回所需结果。
- 聚集函数很高效，比在客户端应用中计算快得多。

## 聚集函数
- 我们经常需要汇总数据而不需要实际数据本身，这种情况下，返回实际数据会浪费时间、处理资源和带宽。
- *聚集函数(aggregate function)*
  - 对某些行运行的函数，计算并返回一个值。
- SQL的聚集函数在各主要SQL实现中得到了相当一致的支持。以下给出5种聚集函数：

| 函数 | 说明 |
| --- | --- |
| AVG() | 返回某列平均数 |
| COUNT() | 返回某列的行数 |
| MAX() | 返回某列的最大值 |
| MIN() | 返回某列的最小值 |
| SUM() | 返回某列值之和 |

### AVG()函数
- AVG()通过对表中行数计数并计算其列值之和，求得该列的平均值。
```sql
SELECT AVG(prod_price) AS avg_price
FROM Products;
```
- 利用`WHERE`子句，`AVG`也可以用来确定特定~列或~行的平均值。
```sql
SELECT AVG(prod_price) AS avg_price
FROM Products
WHERE vend_id = 'DLL01';
```
- 注意：只用于单个列
  - AVG()只能用来确定特定数值列的平均值，而且列名必须作为函数参数给出。
  - 要获得多个列的平均值，必须使用多个AVG()函数。
- 说明：NULL值
  - AVG()函数忽略列值为NULL的行。

### COUNT()函数
- COUNT()函数用于确定表中行的数目或符合特定条件的行的数目。
- COUNT()函数的2种使用方式：
  - 使用COUNT(*)对表中行的数目进行计数，统计总行数，不管表列中包含的是空值还是非空值;
  - 使用COUNT(column)对特定列中具有值的行进行计数，忽略NULL值。
```sql
-- 对所有行计数，不管行中各列有什么值
SELECT COUNT(*) AS num_cust
FROM Customers;
-- 统计符合特定条件的行数
SELECT COUNT(cust_email) AS num_cust
FROM Customers;
```
- 说明：NULL值
  - 如果指定列名，则COUNT()函数会忽略指定列的值为空的行;
  - COUNT()函数中用星号`*`时，不忽略NULL值，统计总行数(总不可能所有列都为NULL)。

### MAX()函数
- MAX()返回指定列中的最大值。
  - MAX()要求指定列名。
```sql
SELECT MAX(prod_price) AS max_price
FROM Products;
```
- 提示：对非数值数据使用MAX()
  - MAX()一般用来找出最大日期值或数值;
  - 但许多DBMS允许用它返回任意列中的最大值，包括返回文本列中的最大值。
  - 用于文本数据时，返回该列排序后的最后一行。

### MIN()函数
- MIN()返回指定列的最小值。
  - 要求指定列名。
```sql
SELECT MIN(prod_price) AS min_price
FROM Products;
```
- 提示：对非数值数据使用MIN()
  - MIN()一般用于找出最小的数值和日期值;
  - 许多DBMS允许用它来返回任意列中的最小值，包括文本列;
  - 用于文本列时，返回该列排序后最前面的行。
- 说明：NULL值
  - MIN()函数忽略列值为NULL的行。
### SUM()函数
- SUM()用来返回指定列值的和。
```sql
SELECT SUM(quantity) AS items_ordered
FROM OrderItems
WHERE order_num = 20005;
```
- SUM()也可以用来合计计算值，即返回计算字段的和。
```sql
SELECT SUM(item_price*quantity) AS total_price
FROM OrderItems
WHERE order_num = 20005;
```
- 提示：在多个列上进行计算
  - 如本例所示，利用标准的算数运算符，所有聚集函数都可以用来执行多个列上的计算。
- 说明：NULL值
  - SUM()函数忽略值为NULL的行。

## 聚集不同值
- 上述所有聚集函数都可以如下使用：
  - ALL：对所有行执行计算，是不指定参数的默认行为;
  - DISTINCT：只包含不同的值。
- 提示：ALL为默认
  - ALL参数是不需要指定的，因为是默认行为;
  - 在不指定DISTINCT时，就假定为ALL。
- 说明：不要在Access中使用
  - MS Access在聚集函数中不支持DISTINCT，Access需要用子查询把DISTINCT数据返回到外部的SELECT COUNT(*)语句。
```sql
SELECT AVG(DISTINCT prod_price) AS avg_price
FROM Products
WHERE vend_id = 'DLL01';
```
- 注意：DISTINCT不能用于COUNT(*)
  - DISTINCT只能用于COUNT()且指定列名，DISTINCT不能用于COUNT(*)。
- 提示：将DISTINCT用于MAX()和MIN()
  - 技术上是可行的，但是这么做实际上没什么价值，因为值的互异性并不影响。
- 说明：其他聚集参数
  - 有些DBMS还支持其他聚集参数(除DISTINCT和ALL以外)，如支持对查询结果的子集进行计算的TOP和TOP PERCENT。

## 组合聚集函数
- SELECT语句可根据需要包含多个聚集函数：
```sql
SELECT COUNT(*) AS num_items,
MIN(prod_price) AS  price_min,
MAX(prod_price) AS price_max,
AVG(prod_price) AS price_avg
FROM Products;
```
- 注意：取别名
  - 指定别名以包含某个聚集函数的结果时，不应该使用表中实际的列名，许多SQL是不支持这样做的，这样可能会产生模糊的错误消息。
