# 使用视图
>视图是虚拟的表，与包含数据的表不仅一样，视图只包含使用时动态检索数据的查询(视图实际上是一组查询语句)。

## 为什么使用视图
视图有以下一些常见应用
- 重用SQL语句
- 简化复杂的SQL操作
  - 在编写查询后，可以方便地重用它而不用知道其剧本查询细节
- 使用表的一部分而不是整个表
- 保护数据
  - 可以授予用户访问表的特定部分的权限，而不是整个表的访问权限
- 更改数据格式和表示
  - 视图可以返回和底层表的表示和格式不同的数据
创建视图之后，可以用与表基本相同的方式使用它们。

重要的是，要知道**视图仅仅是用来查看存储在别处数据的一种设施，视图本身不包含数据，因此返回的数据是从其他表中检索出来的**。在添加或更改这些表中的数据时，视图将返回改变过的数据。


*注意：性能问题*
>因为视图不包含数据，所以每次使用视图前，都必须处理查询执行时需要的所有检索，所以如果创建了复杂的视图，性能会下降的很厉害。

## 视图的规则和限制

关于视图创建和使用的一些最常见的规则和限制:
- 与表一样，视图必须唯一命名(不能给视图取与其他表或视图同样的名字)
- 对于可以创建视图的数目没有限制
- 创建视图必须用于足够的访问权限，权限通常由数据库管理人员授予
- 视图可以嵌套
- 许多DBMS禁止在视图查询中使用ORDER BY子句
- 有许多DBMS要求对返回的所有列进行命名，如果列时计算字段则需要使用别名
- 视图不能索引，也不能有关联的触发器或默认值
- 有些DBMS会把视图作为只读的查询
- 有些DBMS允许创建这样的视图，不能进行导致行不再属于视图的插入或更新

## 创建视图

用`CREATE VIEW`语句来创建，只能用于创建不存在的视图
用`DROP VIEW viewname`删除视图
视图重命名必须先删除，再进行重新构建

### 利用视图简化复杂的联结
```sql
CREATE VIEW ProductsCUtomers AS
SELECT cust_name,cust_contact,prod_id
FROM  Customers,Orders,OrderItems
WHERE Customers.cust_id = Orders.cust_id
AND OrderItems.order_num = Orders.order_num;
```
上述视图联结了三个表，使用该视图简化查询操作如下
```sql
SEELECT cust_name,cust_contact
FROM ProductCustomers
WHERE prod_id = 'RGAN01';
```

*提示:创建可重用的视图*
>创建不绑定特定数据的视图，如上，视图返回订购所有产品而不仅仅是RGAN01的顾客，扩展视图的范围导致它更可能被重用，且可能更有用，这样就不需要创建和维护多个类似视图。

### 用视图重新格式化检索出的数据
```sql
CREATE VIEW VendorLocations AS
SELECT RTRIM(vend_name)+'('+RTRIM(vend_country)+')'
	AS vend_title
FROM Vendors;
```
*说明:SELECT约束全部适用*
>视图只包含一个SELECT语句，这个语句的语法必须遵循具体DBMS的所有规则和约束，所以会有多个创建视图的语句版本。

### 用试图过滤不想要的数据
视图中也可以包含`WHERE`子句用于过滤。
```
CREATE VIEW CustomerEMailList AS
SELECT cust_id, cust_name, cust_email
FROM Customers
WHERE cust_email IS NOT NULL;
```
*说明：WHERE子句的自动组合*
>从视图检索数据时如果使用了一条WHERE子句，则在视图中的WHERE子句和传递给视图的WHERE子句将自动组合。

### 使用视图与计算字段
```sql
CREATE VIEW OrderItemsExpanded AS
SELECT order_num,
	prod_id,
	quantity,
	item_price,
	quantity*item_price AS expanded_price
FROM OrderItems;
```
