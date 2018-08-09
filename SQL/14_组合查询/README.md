# 组合查询
- 如何利用UNION操作符将多条SELECT语句组合成一个结果集。

## 组合查询
SQL也允许执行多个查询(多条SELECT语句)，并将结果作为一个查询结果集返回。这些组合查询通常称为并(union)或符合查询(compound query)。

主要有两种情况使用组合查询：
- 在一个查询中从不同的表返回结构数据
- 对一个表执行多个查询，按一个查询返回所有数据

> 任何具有多个WHERE子句的SELECT语句都可以作为一个组合查询。

## 创建组合查询
可以用`UNION`操作符来组合数条SQL查询。
### 使用UNION
只要给出每条SELECT语句，在各条语句之间放上关键字UNION。
```
SELECT cust_name, cust_contact, cust_email
FROM Customers
WHERE cust_state IN ('IL','IN','MI');
UNION
SELECT cust_name, cust_contact,cust_email
FROM Customers
WHERE cust_name = 'FUN4ALL';
```
对于较复杂的过滤条件，或从多个表中检索数据的情形，UNION可能会比较易读。

UNION的一些使用规则：
- UNION必须由两条或两条以上的SELECT语句组成，语句之间用关键字`UNION`分开；
- UNION中的各个查询必须包含相同的列、表达式或聚集函数(不需要以相同次序列出)；
- 列数据类型必须兼容，不必完全相同，但必须可以隐式转换。

### 包含或取消重复的行
UNION会自动去除重复的行。
> UNION几乎总是完成与多个WHERE条件相同的工作。

### 对组合查询结果排序
在使用UNION组合查询时，只能使用一条ORDER BY子句，必须位于最后一条SELECT语句之后。这个ORDER BY是对UNION查询返回的结果集做排序。
```
SELECT cust_name, cust_contact, cust_email```
FROM Customers
WHERE cust_state IN ('IL','IN','MI');
UNION
SELECT cust_name, cust_contact,cust_email
FROM Customers
WHERE cust_name = 'FUN4ALL'
ORDER BY cust_name, cust_contact;
```
