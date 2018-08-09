# 创建高级联结
- 一些其他联结
- 如何使用表别名
- 如何对被联结的表使用聚集函数

## 使用表别名
SQL除了对列名和计算字段使用别名，还允许给表名起别名。主要有两个好处
- 允许缩短SQL语句；
- 允许在一条SELECT语句中多次使用相同的表。
```
-- 给表名起别名
SELECT cust_name, cust_contact
FROM Customers AS C, Orders AS O, OrderItems AS OI
WHERE C.cust_id = O.cust_id
AND OI.order_num = O.order_num
AND prod_id = 'RGAN01';
```

注意：表别名只在查询执行中使用，列表名会返回到客户端， 但是表别名不返回到客户端。

## 使用不同类型的联结
除内联结以外的三种其他联结：
- 自联结(self-join)
- 自然联结(natural join)
- 外联结(outer join)
### 自联结
```
SELECT c1.cust_id ,c1.cust_name, c1.cust_contact
FROM Customers AS c1, Customers AS c2
WHERE c1.cust_name = c2.cust_name
AND c2.cust_contact = 'Jim Jones';
```

> 自联结常用来代替从相同表中检索数据的使用子查询语句。

### 自然联结
自然联结排除多次出现，使每一列只返回一次。
自然联结要求你只能选择那些唯一的列，一般通过对一个表使用通配符(`SELECT *`)，而其他表的列使用明确的子集来完成。

```sql
SELECT C.*,O.order_num, O.order_date,
	OI.prod_id, OI.quantity ,OI.item_price
FROM Customers AS C, Orders AS O, OrderItems AS OI
WHERE C.cust_id = O.cust_id
AND OI.order_num = O.order_num
AND prod_id = 'RGAN01';
```

### 外联结
有时候还需要包含两个表中没有关联行的那些行。
```sql
SELECT Customers.cust_id, Orders.order_num
FROM Customers LEFT OUTER JOIN Orders
ON Customers.cust_id = Orders.cust_id;
```
其中`OUTER JOIN`指定联结类型，而`LEFT`/`RIGHT`指定包括其所有行的表。

还有一种联结，称为全外联结(full outer join)。

## 使用带聚集函数的联结
聚集函数用来汇总数据。它可以配合联结一起使用。
```sql
SELECT Customers.cust_id
	COUNT(Orders.order_num) AS num_ord
FROM Customers INNER JOIN Orders
ON Customers.cust_id = Orders.cust_id
GROUP BY Customers.cust_id;
```
