# 使用游标
- 什么是游标
- 如何使用游标

## 游标
- **结果集**
> SQL查询所检索出的结果。

- 游标的作用
  - 有时，我们需要在检索出来的行中前进或后退一行或多行，这就是游标的用途所在

游标(cursor)是一个存储在DBMS服务器上的数据库查询(但并不是一个SELECT语句)，在存储了游标之后，应用程序可以根据需要滚动或浏览其中的数据。

游标主要用于交互式应用，其中用户需要滚动屏幕上的数据，并对数据进行浏览或做出更改。

## 使用游标
使用游标分为以下几个步骤：
- 使用游标前，必须声明/定义它。(只是定义要使用的SELECT语句和游标选项)
- 一旦声明，就必须打开游标以供使用
- 对于填有数据的游标，根据需要取出各行
- 在结束游标使用时，必须关闭游标，可能的话释放游标

### 创建游标
使用`DECLARE`创建游标，`DECLARE`命名游标，并定义相应的`SELECT`语句，根据需要带`WHERE`和其他子句。


创建游标的MySQL、MariaDB、SQL Server版本：
```
DECLARE CustCursor CURSOR
FOR
SELECT * FROM Customers
WHERE cust_email IS NULL
```

### 打开并使用游标
- 打开游标用`OPEN CURSOR`语句。
```
OPEN CURSOR CustCursor
```
在处理`OPEN CURSOR`语句时，执行查询，存储检索出的数据以供浏览和滚动。

- 用`FETCH`访问游标数据。
`FETCH`指出要检索哪些行，从何处检索它们以及将它们放置在何处(变量名)。

以SQL Server的操作举例
```
DECLARE TYPE CustCursor IS REF CURSOR
	RETURN Customers%ROWTYPE;
DECLARE CustRecord Customers%ROWTYPE
BEGIN
	OPEN CustCursor;
	LOOP
	FETCH CustCursor INTO CustRecord;
	EXIT WHEN CustCursor%NOTFOUND;
	...
	END LOOP;
	CLOSE CustCursor;
END;	
```

### 关闭游标
游标在使用完毕时需要关闭。
`CLOSE`语句用来关闭游标。游标一旦关闭，如不再次打开将不能使用，第二次使用它时将不需要再声明，只需要用`OPEN`打开它即可。

DB2、Oracle和PostgreSQL的语法：
```
CLOSE CustCursor
```

SQL Server中还会要求明确释放游标占用的资源
```
CLOSE CustCursor
DEALLOCATE CURSOR CustCursor
```


