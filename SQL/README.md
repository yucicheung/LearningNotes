# 高级SQL特性
介绍SQL涉及的几个高级数据处理特性
- 约束
- 索引
- 触发器

## 约束
正确地进行关系数据库设计，需要一种方法保证只在表中插入合法数据

**约束**
> 管理如何插入或处理数据库数据的规则。

大多数约束是在表中定义的，用`CREATE TABLE`或`ALTER TABLE`语句。

### 主键
主键是一种特殊的约束，用来保证一列(或一组列)中的值是唯一的，而且永不改动。即表中的一列(或一组列)可以唯一标识表中的每一行。
没有主键，要安全地UPDATE或DELETE特定行而不影响其他行会非常困难。

表中任意列满足以下条件，就可用于主键
— 任意两行的主键值都不相同
- 每行都具有一个主键值(不允许为NULL)
- 包含主键值的列从不修改或更新
- 主键值不能重用，如果从表中删除某一行，其主键值不分配给新行。

创建时定义主键
```sql
CREATE TABLE Vendors
(
	vend_id		CHAR(10)	NOT NULL PRIMARY KEY,
	vend_name 	CHAR(50)	NOT NULL,
	vend_address	CHAR(50)	NULL,
	vend_city	CHAR(50)	NULL,
	vend_state	CHAR(5)		NULL,
	vend_zip	CHAR(10)	NULL,
	vend_country	CHAR(50)	NULL
);
```

创建后选择主键
```sql
ALTER TABLE Vendors
ADD CONSTRAINT PEIMARY KEY(vend_id);
```

### 外键
外键是表中的一列，其值必须在**另一表的主键**中。外键是保证引用完整系的极其重要的部分，

BMSCREATE TABLE Orders
(
	order_num	INTEGER		NOT NULL	PRIMARY KEY,
	order_date	DATETIME	NOT NULL,
	cust_id		CHAR(10)	NOT NULL	REFERENCES	Customers(cust_id)
);
```
或者用`ALTER TABLE`中用`CONSTRAINT`完成
```sql
ALTER TABLE Orders
ADD CONSTRAINT
FOREIGN KEY (cust_id) REFERENCES Customers(cust_id);
```

*提示:外键有助防止意外删除*
> 在定义外键后，DBMS不允许删除在另一个表中具有关联行的行；如不能删除关联订单的顾客，删除顾客的方法是首先删除相关的订单，由于需要一系列删除，因此利用外键可以放置意外删除数据。
> 有的DBMS支持级联删除(cascading delete)，若启用，则该特性在从一个表中删除行时将删除所有相关的数据。

### 唯一约束
唯一约束用来保证一列(或一组列)中的数据是唯一的。

它们**与主键有以下重要差别：**
- 表可以包含多个唯一约束，但每个表只允许一个主键
- 唯一约束列可包含NULL值
- 唯一约束列可以修改或更新
- 唯一约束列的值可以重复使用
- 与主键不同，唯一约束不可以用来定义外键

唯一约束的语法类似其他约束的语法。唯一约束可以用`UNIQUE`关键字在表定义中定义，也可以用单独的CONSTRAINT定义。

### 检查约束
检查约束用来保证一列(一组列)中的数据满足一组指定条件。

常见用途：
- 检查最大/最小值
- 指定范围
- 只允许特定的值

举例如下：
```sql
CREATE TABLE OrderItems
(
	order_num	INTEGER		NOT NULL,
	order_item	INTEGER		NOT NULL,
	prod_id		CHAR(10)	NOT NULL,
	quantity	INTEGER		NOT NULL CHECK(quantity>0),
	item_price	MONEY		NOT NULL
);
```
```SQL
AKTER TABLE Customers
ADD CONSTRAINT CHECK(gender LIKE '[MF]')
```

## 索引
索引用来排序数据以加快搜索和排序操作的速度。
可以在一个或多个列上定义索引，使DBMS保存其内容的一个排过序的列表。
DBMS搜索排过序的索引，找出匹配的位置，然后检索这些行。

关于索引的一些说明：
- 索引改善检索性能，但是降低数据插入、修改和删除的性能。
- 索引数据要占用大量存储空间。
- 并非所有数据都适合做索引，具有更多可能值的数据更适合做索引。
- 索引用于数据过滤和数据排序，如果经常以某种特定的顺序排序数据，该数据可能适合做索引。
- 可以在索引中定义多个列。

索引用`CREATE INDEX`创建
```
CREATE INDEX prod_name_ind
ON Products (prod_name);
```

## 触发器
触发器使特殊的存储过程，在指定的数据库活动发生时自动执行。触发器可以与特定表上的INSERT、UPDATE和DELETE操作(或组合)相关联。
触发器与存储过程不同，它是与某个特定表相关联的。

触发器的一些常见用途：
- 保证数据一致
- 基于某个表的变动在其他表上执行活动
- 进行额外的验证并根据需要回退数据
- 计算计算列的值或更新时间戳

举个例子(SQL Server)
```
CREATE TRIGGER customer_state
ON Customers
FOR INSERT,UPDATE
AS
UPDATE Customers
SET cust_state = UPPER(cust_state)
WHERE Customers.cust_id = inserted.cust_id
```

*提示：约束比触发器更快，应尽量使用约束*

## 数据库安全
任何安全系统的基础都是用户授权和身份确认。
安全性使用SQL的GRANT和REVOKE来管理。
