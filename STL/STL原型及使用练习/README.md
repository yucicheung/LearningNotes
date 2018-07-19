[source](https://www.dre.vanderbilt.edu/~schmidt/PDF/stl.pdf)

## what is STL
- 一系列可组合的类和函数模板
  - Helper class & function templates: operators, pair
  - Container & iterator class templates
  - Generic algorithms that operate over iterators
  - Function objects
  - Adaptors

- 使C++中泛型编程成为现实
  - Each generic algorithm can operate over any iterator for which the necessary operations are provided.
  - **Extensible**：can support new algorithms, containers,iterators.

## Generic Programming : Why Use STL?

- Reuse可复用性:"write less , do more"
  - STL隐藏了复杂，乏味和易于出错的细节
  - 程序员可以专注于问题本身
  - Type-safe plug compatibility between STL components(类型安全由强类型语言做到，兼容性由模板类的设计完备性做到？)

- Flexibility灵活性
  - Iterators decouple(脱钩) algorithms from containers
  - 可以很容易地支持意外的(unanticipated)组合

- Efficiency高效性
  - Templates avoid virtual function overhead
  - Strict attention to time complexity of algorithms

## Overview of STL concepts & features
## STL特性：容器 迭代器 算法
- Containers容器
  - 有序容器Sequential : vector deque list
  - 关联容器Associative : set multiset map multimap
  - 容器适配器Adapters: stack queue prority_queue

- Iterators迭代器
  - input,output, forward, bidirectional, random access
  - Each container declares a trait for the type of iterator it provides.

## A complete STL Example

## Reference for more information on STL


