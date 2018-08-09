# 使用存储过程
存储过程是一系列SQL语句的打包。
## 什么是存储过程
在实际操作中经常会有一些复杂的操作需要多条语句才能完成，举个例子：
- 为了处理订单，必须核对以保证库存中有相应的物品
- 如果物品有库存，需要预定时，不再出售给其他人，并且减少物品数据以反映正确的库存量
- 库存中没有的物品需要订购，这需要与供应商进行交互
- 当物品发生入库和退订时，需要通知相应的顾客
当然可以单独编写每条SQL语句，并根据结果有条件地执行其他语句，只不过在每次这个处理时，都要做这些工作。

但也可以**创建存储过程**，简单地说，**存储过程就是为以后使用而保存的一条或多条SQL语句**，可以将其视为批文件，虽然它们的作用不仅限于批处理(批处理是一种简化的脚本语言，将对一系列/批数据的处理语句打包在一起，视作批处理)。

## 为什么使用存储过程
一些主要的原因：
- 把处理封装在一个易用单元中了，可以简化复杂的操作。
- 因为所有开发人员和应用程序都使用同一存储过程，所用代码都相同，因此保证了数据的一致性。
- 简化对变动的管理。如果表名、列名或业务逻辑有变化，只需要改变存储过程的代码。
  - 延伸出安全性，通过存储过程可以限制对基础数据的访问，减少数据讹误。
- 存储过程常以编译过的形式存储，因此DBMS处理命令所需的工作量少，提高了性能。
- 存在一些只能用在单个请求中的SQL元素和特性，存储过程可以使用它们来编写功能更强更灵活的代码(一个请求实现复合功能)。

注意：
- 不同的DBMS中的存储过程语法不同，因此编写真正可移植的存储过程几乎不可能。

*说明*
> 大多数DBMS将编写存储过程所需的安全和访问权限与执行存储过程所需的安全和访问权限区分开来。

## 执行存储过程
执行存储过程的SQL语句是`EXECUTE`,`EXCUTE`接受存储过程名和需要传递给它的任何参数。
```sql
EXECUTE AddNewProduct('JTS01',
			'Stuffed Eiffel TOwer',
			6.49,
			'Plush stuffed toy with the text La Tour EIffel in red white and blue'
			);
```
上述`AddNewProduct`就是一个存储过程，实现将一个新产品添加到Products表中。
而Products的主键`prod_id`则不依赖用户输入，而是自动由程序生成。

因此，存储过程完成有以下工作：
- 验证传递的数据，保证4个参数都有值；
- 生成用作主键的唯一ID；
- 将新产品插入Products表，在合适的列中存储生成的主键和传递的数据。

## 创建存储过程
存储过程的创建用`CREATE PROCEDURE`实现。

举例一个SQL Server的存储过程实现，其功能为：在Orders表中插入一个新订单。
```sql
CREATE PROCUDURE NewOrder @cust_id CHAR(10)
AS
-- Declare varibale for order number
DECLARE @order_num INTEGER
-- Get current highest order number
SELECT @order_num = MAX(order_num)
FROM Orders
-- Determine next order number
SELECT @order_num = @order_num +1
-- Insert new order
INSERT INTO Orders(Order_num,order_date,cust_id)
VALUES(@order_num,GETDATE(),@cust_id)
-- Return order number
RETURN @order_num;
```

*说明：代码注释*
> 对所有代码的标准注释方式是在之前放置`--`，这点所有的DBMS都支持。
