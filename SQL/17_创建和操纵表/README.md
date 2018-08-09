# 创建和操纵表
- 创建表CREATE TABLE
- 更改表ALTER TABLE
- 删除表DROP TABLE
## 创建表
之前是对表数据的操纵，还可以用来执行数据库和表的操作。

创建表，使用SQL的`CREATE TABLE`语句。

### 表创建基础
一个示例：
```sql
CREATE TABLE Products
(
	prod_id		CHAR(10)	NOT NULL,
	vend_id 	CHAR(10)	NOT NULL,
	prod_name	CHAR(254)	NOT NULL,
	prod_price	DECIMAL(8,2)	NOT NULL,
	prod_desc	VARCHAR(1000)	NULL
);
```
各列之间用逗号分隔，整条语句以圆括号后的分号结束。
MySQL语句中，varchar需要替换为text。
**NULL**表示没有值或缺值

> 推荐SQL使用缩进格式，会更容易阅读和编辑

> 替换现有的表：需要先手动删除该表，再重建它

> 只有不允许NULL的列才可以作为主键

### 指定默认值
SQL允许用`DEFAULT`指定默认值，插入行时如果不给出值，则DBMS将采用默认值。
```
CREATE TABLE OrderItems
(
	order_num	INTEGER		NOT NULL,
	order_item	INTEGER		NOT NULL,
	prod_id		CHAR(10)	NOT NULL,
	quantity	INTEGER		NOT NULL	DEFAULT 1,
	item_price	DECIMAL(8,2)	NOT NULL
);

```
默认值常用于日期或者时间戳列。MySQL使用`DEFAULT CURRENT_DATE()`指定系统日期作为默认日期。

## 更新表
更新表用`ALTER TABLE`语句。

使用该语句需要注意：
- 理想情况下，不要再表中包含数据时对其进行更新
- 所有DBMS允许给表增加列，但所增加列的数据类型有所限制
- 许多DBMS不允许删除或更改表中的列，但允许重命名表中的列
- 许多DBMS限制对已经填有数据的列进行更改，对未填有数据的列几乎没有限制

给已有表增加列时DBMS都支持的唯一操作：
```
ALTER TABLE Vendors
ADD vend_phone CHAR(20);
```

删除列：
```
ALTER TABLE Vendors
DROP COLUMN vend_phone
```
> 在ALTER TABLE前应该在做好完整的备份。

## 删除表
使用`DROP TABLE`命令。
```
DROP TABLE CustCopy;
```
> 关系会防止意外删除，除非该关系被先删除。

## 重命名表
DB2、MariaDB、MySQL、Oracle和PostgreSQL使用`RENAME`语句
SQL Server使用`sp_rename`存储过程
SQLite使用`ALTER TABLE`


