#include<iostream>
#include<string>
#include<list>
#include<iterator>

int main()
{
	std::list<std::string> fruitList;	
	fruitList.push_front("apple");
	fruitList.push_back("banana");
	fruitList.push_back("carrot");

	std::ostream_iterator<std::string> outIt(std::cout,"\n");//定义有名迭代器，插入什么类型，输出到什么对象，及分割符号
	std::copy(fruitList.begin(),fruitList.end(),outIt);
	//std::reverse_copy(fruitList.begin(),fruitList.end(),outIt);
	std::copy(fruitList.rbegin(),fruitList.rend(),outIt);

	return 0;
}
