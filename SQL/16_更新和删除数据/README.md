# 更新和删除数据
- 利用UPDATE操作表数据
- 利用DELETE操作表数据

## 更新数据
使用UPDATE更新表中数据，有两种使用方式：
- 更新表中的特定行
- 更新表中的所有行
> 在使用UPDATE时不要省略WHERE子句，否则就会更新表中的所有行。

UPDATE语句由三部分组成：
- 要更新的表；
- 列名和它们的新值；
- 确定要更新哪些行的过滤条件。

更改一个行：
```sql
UPDATE Customers
SET cust_email = 'kim@thetoystore.com'
WHERE cust_id = '1000000005';
```

更改多个行：
```
UPDATE Customers
SET cust_contact = 'Sam Roberts'
	cust_email = 'sam@toyland.com'
WHERE cust_id = '1000000006';
```
注意：每个键值对之间用逗号分隔，最后一列之后不用逗号。

## 删除数据
用DELETE从一个表中删除数据，有两种使用方式：
- 从表中删除特定的行
- 从表中更新所有行

> 注意不要省略WHERE子句

删除一行
```sql
DELETE FROM Customers
WHERE cust_id = '1000000006';
```

> 外键限制保证DBMS的引用完整性，即不允许通过未知的供应商ID插入它，也会放置删除某个关系需要用到的行。

> DELETE不删除表本身，只是删除表的内容。要更快删除表中的所有行的内容，使用`TRUNCATE TEBLE`命令。

## 一些指导原则
- 除非确实打算更新和删除每一行，否则必须加上`WHERE`子句
- 在UPDATE或DELETE前，先使用SELECT进行测试，保证过滤的是正确的记录

