# 插入数据
- 用SQL的INSERT语句将数据插入表中
## 数据插入
`INSERT`用来将行插入到数据库表。插入有以下方式：
- 插入完整的行；
- 插入行的一部分；
- 插入某些查询的结果。

> 在使用INSERT语句时可能需要客户端/服务器DBMS中的特定安全权限。

### 插入完整的行
最安全并且移植性好的INSERT语句需要指定每个列名：
```sql
INSERT INTO Customers(cust_id,
			cust_name,
			cust_address,
			cust_city,
			cust_state,
			cust_zip,
			cust_country,
			cust_contact,
			cust_email)
VALUES('1000000006',
	'Toy Land',
	'123 Any Street',
	'New York',
	'NY',
	'11111',
	'USA',
	NULL,
	NULL);
```
values列表中的相应值将填入列表中的对应项。

> 不要使用没有明确给出列的INSERT语句，给出列能使SQL代码继续发挥作用。

> VALUES的数目必须正确，否则会提示错误信息，相应行不能插入。

### 插入部分行
INSERT还可以省略列，表示可以只给某些列提供值，某些列不提供值。

**注意，省略列必须要表的定义允许**
- 该列定义允许为NULL值
- 表定义中使用了默认值

### 插入检索出的数据
INSERT还可以用来将SELECT语句的结果插入表中，即`INSERT SELECT`。
```sql
INSERT INTO Customers(cust_id,
			cust_contact,
			cust_email,
			cust_name,
			cust_address,
			cust_City,
			cust_state,
			cust_zip,
			cust_country)
SELECT cust_id,cust_contact,cust_email,cust_name, cust_address, cust_city,cust_state,cust_zip,cust_country
FROM CustNew;
```
一般`SELECT`只插入一行，但上述`INSERT SELECT`语句实现插入多行。

> DBMS不关心SELECT返回的列名，只关心列的位置，实现对应位置的列值填充。

## 从一个表复制到另一个表
使用`SELECT INTO`语句将一个表的内容复制到一个全新的表。
```sql
SELECT *
INTO CustCopy
FROM Customers;
```
实现从表中导出内容到另一个表。

在使用SELECT INTO时的注意事项(将唯一结果集导出)：
- 任何SELECT选项和子句都可以使用，包括`WHERE`和`GROUP BY`;
- 可以利用联结从多个表中插入数据；
- 不管从多少个表中检索数据，数据都只能插入到一个表中。
