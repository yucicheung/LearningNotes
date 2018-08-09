# 联结表
- 什么是联结
- 为什么使用联结
- 如何写使用联结的SELECT语句

## 联结
SQL最强大的功能之一就是在数据查询的执行中联结(join)表，联结是是使用SQL的SELECT能执行的最重要的操作。
### 关系表
关系表设计的关键是，相同的数据出现多次绝不是一件好事，这是关键数据库设计的基础。关系表的设计就是要把信息分解成多个表，一类数据一个表。各表通过某些共同值相互关联(所以才叫关系数据库)。
这样做的好处是：
- 信息不重复，不会浪费时间和空间
- 如果其中一类信息变动，只需要更改该表，其他关系表中的数据不用变动
- 数据不重复，因此数据是一致的，则处理数据和生成报表更简单

*关系数据库的可伸缩性远比非关系数据库好*
> 能够适应不断增加的工作量而不失败，可称为伸缩性好

如果数据存储在多个表中，如何用一条语句就检索出数据呢？**答案是使用联结**。
> 联结是一种机制，用来在一条SELECT语句中关联表，因此称为联结。使用特殊的语法，可以联结多个表返回一组输出。

## 创建联结
一个联结的例子
```sql
SELECT vend_name,prod_name,prod_price
FROM Vendors,Products
WHERE Vendors.vend_id = Products.vend_id;
```
上述两表就是用WHERE进行了联结，并且注意，由于消除歧义，上述使用了完全限定列名。

*完全限定列名*
> 完全限定列名是为了消除歧义而使用的，格式是*一个据点分割表名和列名*。

### WHERE子句的重要性
WHERE子句作为过滤条件，只匹配那些符合联结条件的行。如果没有联结条件的表关系，返回的结果为笛卡尔积。
返回笛卡尔积的联结也称为叉联结(cross join)。

### 内联结
目前为止的联结称为等值联结(equijoin)，基于两个表之间的相等测试。这种联结也称为内联结(inner join)。我们可以在语句中明确指定联结的类型，
```sql
SELECT vend_name, prod_name, prod_price
FROM Vendors INNER JOIN Products
ON Vendors.vend_id = Products.vend_id;
```
### 联结多个表
SQL不限制一条SELECT语句中可以联结的表的数目，创建联结的基本规则也相同，首先列出所有表，如何定义表之间的关系。

*注意：性能考虑*
> DBMS在运行时关联指定的每个表，以处理联结，这种处理可能非常耗费资源，因此注意不要联结不必要的表，联结的表越多，性能下降越厉害。

联结可以代替子查询
```sql
-- 子查询
SELECT cust_name,cust_contact
FROM Customers
WHERE cust_id IN (SELECT cust_id
		FROM Orders
		WHERE order_nunm IN (SELECT order_num
					FROM OrderItems
					WHERE prod_id = 'RGAN01'));
```
```sql
SELECT cust_name,cust_contact
FROM Customers, Orders, OrderItems
WHERE Customers.cust_id = Orders.cust_id
AND OrderItems.order_num = Orders.order_nunm
AND prod_id = 'RGAN01';
```
