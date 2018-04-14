# 高级数据过滤

## 摘要
- 如何使用`AND`和`OR`操作符组合成WHERE子句
- 如何明确地管理求值顺序
- 如何使用`IN`和`NOT`操作符

## 组合WHERE子句
- *操作符(operator)*
  - 用来联结或改变WHERE子句的关键字，也称为逻辑操作符(logic operator)。
- 要进行更强的过滤控制时，SQL允许给出多个WHERE子句，这些子句间可以用`AND`或`OR`来控制逻辑关系。
### `AND`操作符
- `AND`
  - 用在WHERE子句中的关键字，用来检索同时满足左右给定条件的行;
  - 要满足多个指定条件时，每个条件间都要使用AND关键字。
```sql
SELECT prod_id, prod_name,prod_price
FROM Products
WHERE vend_id = 'DLL01'AND prod_price<=4;
```
### `OR`操作符
- `OR`
  - WHERE子句中使用的关键字，指示DBMS检索匹配任一条件的行;
  - 许多的DBMS在OR WHERE子句的第一个条件得到满足的情况下，就不再计算第二个条件了(在第一个条件满足时，不论第二个条件是否满足)，相应行都会被检索出来;
```sql
SELECT prod_name, prod_price
FROM Products
WHERE vend_id = 'DLL01' OR vend_id = 'BRS01';
```
### 求值顺序
- WHERE子句可以包含任意数目的`AND`和`OR`操作符，允许两者结合以进行更复杂、高级的过滤。
- SQL，像大多数语言一样，在处理OR操作符前，优先处理AND操作符，即AND操作符的优先级高于OR操作符。
- `()`:要改变运算顺序时，采用圆括号对操作符进行明确分组;
  - 圆括号`()`具有比`AND`和`OR`更高的优先级，所以DBMS会优先过滤圆括号内的条件。
```sql
SELECT prod_name,prod_price
FROM Products
WHERE (vend_id = 'DLL01' OR vend_id = 'BRS01')
	AND prod_price>=10;
```
- 提示：在WHERE子句中使用圆括号
  - 任何时候使用居于and和or操作符的where子句，都应该使用圆括号明确地分组操作符;
  - 不要过分依赖默认求值顺序;
  - 使用圆括号并没有坏处，能够消除歧义，易于阅读。

## `IN`操作符
- `IN`
  - WHERE子句中用来指定要匹配值的清单的关键字，功能与`OR`相当;
  - `IN`操作符用来指定条件范围，范围中的每个条件都可以进行匹配;
  - `IN`取一组由逗号分隔、括在圆括号中的合法值。
```sql
SELECT prod_name, prod_price
FROM Products
WHERE vend_id IN ('DLL01','BRS01')
ORDER BY prod_name;
```
- `IN`操作符的优点：
  - 在有很多合法选项时，IN操作符的语法更清楚、更直观;
  - 在与其他AND和OR操作符组合使用IN时，相比完全用`OR`表示的子句，求值顺序更容易管理;
  - IN操作符一般比一组OR操作符执行得更快;
  - IN的最大优点是可以包含其他select语句，能够更动态地建立where子句(11课)。

## NOT操作符
- `NOT`
  - WHERE子句中用来否定*其后条件*的关键字;
  - NOT从不单独使用，它总是与其他操作符一起使用;
  - NOT关键字可以用在要过滤的列前，也可以放在列后;
```sql
SELECT prod_name
FROM Products
WHERE NOT vend_id = 'DLL01'
ORDER BY prod_name;
```
- `NOT`的优点
  - 在与IN操作符联合使用时，NOT可以非常简单地找出与条件列表不匹配的行(清晰且有效率)。
- 说明：MariaDB中的NOT
  - MariaDB支持使用NOT否定IN、BETWEEN和EXISTS子句;
  - 大多DBMS允许使用NOT否定任何条件。
