# STL容器

## 有序容器
- `std::vector`
  - 是一种动态的array，可以在扩张或者缩减。首尾用`begin()`和`end()`指示。
  - `push_back()`,`pop_back()`
  - 支持随机存取迭代器random access iterators
  - 比C++内建array更强大

- `std::deque`(pronounced "deck")
  - 双端队列，可以在序列的首尾进行高效地插入和删除操作。首尾用`begin()`和`end()`指示。
  - `push_front()`，`pop_front()`

- `std::list`
  - 双向链表，插入和删除操作占用常数时间，同时也没办法进行随机读取，有`begin()`,`end()`,`rend()`,`rbegin()`;
  - `push_back()`,`push_front()`

## 关联容器
- `std::set`
  - 是一种按照升序排列的唯一键(无重复)的集合。
  - `insert()`，成员函数将返回pair，如果完成插入，则bool组件为true，否则为false

- `std::map`
  - 有时称为字典，包含键/值对，键用于对序列排序，值与该键关联。将一个值与每个唯一的(无重复)的键关联起来。`map`的无序版本是`unordered_map`。
  - `std::map<std::string,int>`就组成一个键值对的map类型。
  - The `value_type` is implemented as pair<const Key,Data>。`value_type`是存储在`map`映射中的对象类型的typedef,有`first`和`second`成员。 

- `std::multiset`多重集合， `std::multimap`多重映射
  - 不需要有唯一键(non-unique key)，一个键值可以具有多个相关联的元素数据值。
  - 是容器对pair,因为数据值与键值是不同的类型。

- Notes:**pair辅助类**
  - 这个模板是`map`和`set`关联容器的基础，因为它存储了一对异构数据对(heterogeneous pairs of data together)。
  - 一个pair可以绑定一个键(`first`成员)和一个相关的值(`second`成员)。
  - 模板原型如下
  - 重载操作符如下
```c++
//template prototype
template <typename T,typename U>
struct pair{
	T first;
	U second;
	
	pair(){}
	pair(const T& t, const U& u):first(t),second(u);
}

//operator `==` overload
template <tyoename T,typename U>
inline bool operator ==(const pair<T,U>& lhs, const pair<T,U>& rhs)
{
	return lhs.first==rhs.first&&lhs.second==rhs.second;
}

//operator `<` overload
template <typename T,typename U>
inline bool operator < (const pair<T,U>&lhs, const pair<T,U>& rhs)
{
	return lhs.first<rhs.second &&lhs.first<rhs.second;
}
```
