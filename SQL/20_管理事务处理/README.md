# 管理事务处理
- 什么是事务处理
- 如何利用`COMMIT`和`ROLLBACK`语句管理事务处理
## 事务处理
使用事务处理(transaction processing),通过确保**成批的SQL语句要么完全执行，要么完全不执行，来维护数据库的完整性**。

事务处理是一种机制，用来管理必须成批执行的SQL操作，**保证数据库不包含不完整的操作结果**。利用事务处理，可以保证一组操作不会中途停止，要么完全执行，要么完全不执行。如果没有错误发生，整组语句提交给数据库表；如果发生错误，则进行回退，将数据库恢复到某个已知且安全的状态。

在使用事务处理时，需要知道的几个术语：
- 事务(transaction)指一组SQL语句；
- 回退(rollback)指撤销指定SQL语句的过程；
- 提交(commit)指将未存储的SQL语句结果写入数据库表；
- 保留点(savepoint)指事务处理中设置的临时占位符(placeholder)，可以对它发布回退。

*提示：可以回退到哪些语句*
> 事务处理用来管理INSERT、UPDATE、DELETE语句。不能回退SELECT语句(没有必要)，CREATE或DROP语句。

## 控制事务处理
管理事务的关键在于将SQL语句分解为逻辑块，并明确规定数据何时该回退，何时不该回退。

SQL Server中，会明确要求标识事务处理块的开始和结束。
```
BEGIN TRANSACTION
...
COMMIT TRANSACTION
```

而在MySQL/MariaDB中同等代码为
```
START TRANSACTION
...
```
没有明确标识事务处理在哪里结束，事务一直存在，直到被中断。

`COMMIT`用于保存更改`ROLLBACK`用于撤销。
### 使用ROLLBACK
ROLLBACK命令用于撤销SQL语句。
```sql
DELETE FROM Orders;
ROLLBACK;
```

### 使用COMMIT
一般的SQL语句都是针对数据库表直接执行和编写的，这就是隐式提交(implicit commit)，即提交(写或保存)操作是自动进行的。
**在事务处理块中，提交不会隐式进行**。

进行明确的提交，用`COMMIT`语句。举一个例子，在SQL Server中，
```sql
BEGIN TRANSACTION
DELETE OrderItems WHERE order_num =12345
DELETE Orders WHERE order_num =12345
COMMIT TRANSACTION
```

### 使用保留点
简单的事务可以写入或撤销整个事务，但是复杂的事务可能需要部分提交或回退。

要支持回退部分事务，就必须在事务处理块中的合适位置放置占位符。在SQL中，这些占位符就叫做**保留点**。
在MariaDB、MySQL和Oracle中创建占位符，可以使用SAVEPOINT语句。
```
SAVEPOINT delete1;
```
回退到保留点用
```
ROLLBACK TO delete1;
```

在SQL Server中，采用以下语句
```
SAVE TRANSACTION delete1;
```
回退语法
```
ROLLBACK TRANSACTION delete1;
```
**注意：**每个保留点要取一个能够标识它的唯一名字。

有了保留点以后，在回退时，DBMS就知道要回退到何处。


给一个完整的SQL Server例子：
```
BEGIN TRANSACTION
INSERT INTO Customers(cust_id, cust_name)
VALUES('1000000010','Toys Emporium');
SAVE TRANSACTION StartOrder;
ISNERT INTO Orders(order_num,order_date,cust_id)
VALUES(20100,'2001/12/1','1000000010');
IF @@ERROR <> 0 ROLLBACK TRANSACTION StartOrder;
INSERT INTO OrderItems(order_num,order_item,prod_id,quantity,item_price)
VALUES(20100,1,'BR01',100,5.49);
IF @@ERROR <> 0 ROLLBACK TRANSACTION StartOrder;
INSERT INTO OrderItems(order_num,order_item,prod_id,quantity,item_price)
VALUES(20100,2,'BR03',100,10.99);
IF @@ERROR <> 0 ROLLBACK TRANSACTION StartOrder;
COMMIT TRANSACTION
```
@@ERROR变量为非0时，表示有错误发生。

*提示：保留点越多越好*
> 在SQL代码中设置越多的保留点越好，因为保留点越多，就越能灵活地进行回退。
