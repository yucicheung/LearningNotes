# 分组数据
## 摘要
- 如何使用`GROUP BY`子句对多组数据进行汇总计算，返回每个组的结果
- 如何使用`HAVING`子句过滤特定的组
- `ORDER BY`和`GROUP BY`之间的差异
- `WHERE`和`HAVING`之间的差异

## 数据分组
- 当不再只需要对一组供应商做统计，而是需要对多组供应商的数据分别进行统计时。
- 使用分组可以将数据分为多个逻辑组，对每个组进行聚集计算。
## 创建分组
- 分组用`SELECT`语句的`GROUP BY`子句建立，在按组计算聚集时需要使用。
  - `GROUP BY`指示DBMS分组数据，然后对每个组而不是整个结果集进行聚集。
```sql
SELECT vend_id, COUNT(*) AS num_prods
FROM Products
GROUP BY vend_id;
```
- `GROUP BY`的一些重要规定：
  - GROUP BY子句可以包含任意数目的列，因此可以对分组进行嵌套，更细致地进行分组(先根据一列分组，再根据二列分组)。
  - 如果在GROUP BY子句中嵌套了分组，数据将在最后指定的分组上进行汇总。
  - GROUP BY的子句中列出的每一列都必须是检索列或有效的表达式(但不能是聚集函数)，如果在SELECT中使用表达式，在GROUP BY中也必须使用相同的表达式，而不能使用别名(貌似可以耶)。
  - 大多数SQL不允许GROUP BY带有长度可变的数据类型（如文本或备注型字段）。
  - 除聚集计算语句外，SELECT语句中的每一列都必须在GROUP BY子句中给出。
  - 如果分组中包含具有NULL值的行，则NULL将作为一个分组返回。如果列中有多行NULL值，它们将分为一组。
  - GROUP BY子句中必须出现在WHERE子句之后，ORDER BY子句之前，即必须先按照行级过滤，才能进行组级过滤。
- 提示：ALL子句
  - MS SQL Server等某些SQL支持在GROUP BY子句中使用ALL子句，这个子句可以用于返回所有分组，即使是没有匹配行的分组(此时聚集函数将返回NULL)。
- 注意：通过相对位置指定列
  - 有些SQL支持用SELECT中的相对位置来指定分组，但不是所有SQL都支持，而且用它很容易在编辑SQL语句时出错。
## 过滤分组
- SQL允许过滤分组，用HAVING子句实现，过滤分组时可以利用聚集函数。与WHERE的句法非常相似，但有又很大差别。
- 提示：HAVING支持所有WHERE操作符
  - WHERE子句条件（包括通配符条件和带多个操作符的子句）都适合于HAVING，它们的句法是相同的，只是关键字有差别。
```sql
SELECT cust_id, COUNT(*) AS orders
FROM Orders
GROUP BY cust_id
HAVING COUNT(*)>=2;
```
- WHERE和HAVING的区别：
  - WHERE实现的过滤指定的是行而不是分组，对于WHERE来说是没有分组的概念;HAVING实现的是对分组的过滤。
  - WHERE在数据分组前进行过滤，HAVING在数据分组后进行过滤;
  - WHERE排除的行不包括在分组中。
- 同时使用WHERE和HAVING(HAVING利用聚集函数过滤分组，然后需要WHERE辅助滤出不需要的记录)：
```sql
SELECT vend_id,COUNT(*) AS num_prods
FROM Products
WHERE prod_price >= 4
GROUP BY vend_id
HAVING COUNT(*)>=2;
```
- 说明：使用HAVING和WHERE
  - HAVING和WHERE非常类似，如不指定GROUP BY，则大多数DBMS会等同对待它们。
  - 要清楚HAVING应该结合GROUP BY子句，而WHERE子句用于标准的行级过滤。
## 分组和排序
- GROUP BY和ORDER BY经常万车工相同的工作，但它们非常不同。下表列出它们的差异：

| ORDER BY | GROUP BY |
| --- | --- |
| 对产生的输出排序 | 对行分组，但输出可能不是分组的顺序 |
| 任意列都可以使用（甚至非选择的列也可以使用）| 只可能使用选择列或者表达式列，而且必须使用每个选择表达式 |
| 不一定需要此子句 | 如果与聚集函数一起使用列(或表达式)，则必须使用此子句 |

- 第一点差别非常重要：
  - 就因为你以某种方式分组数据(获得特定的分组聚集值)，并不代表你需要以相同的方式排序输出。

- 提示：不要忘记ORDER BY
  - 一般在使用GROUP BY子句时，应该也给出ORDER BY子句。这是保证数据正确排序的唯一方法。千万不能依赖GROUP BY的排序顺序。
- 说明：Access的不兼容性
  - MS Access不允许按别名排序，解决方法是按照实际的计算字段或字段位置替换别名。
### SELECT子句顺序
- 至今为止学习过的SELECT子句的次序如下表：

| 子句 | 说明(后跟) | 是否必须使用 |
| --- | --- | --- |
| SELECT | 要返回的列或表达式 | 是 |
| FROM | 从中检索数据的表名 | 仅在从表选择数据时使用 |
| WHERE | 行级过滤条件 | 否 |
| GROUP BY | 分组说明(条件) | 仅在按组计算聚集时使用 |
| HAVING | 组级过滤 | 否 |
| ORDER BY | 输出排序顺序 | 否 |


