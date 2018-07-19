#include<iostream>
#include<map>
#include<string>
#include<algorithm>
//map输出升序排列，并且值一般初始化为0
typedef std::map<std::string,int> MyMap;

struct print{
	//对操作符`()`进行重载
	void operator() (const MyMap::value_type &p)//value_type is implemented as pair<const Key, Data>
	{
		std::cout<<"key:"<<p.first<<" value:"<<p.second<<std::endl;
	}
};//class和struct需要在末尾添加`;`号，class是struct的扩展，可以被继承


int main()
{
	MyMap mymap;
	for(std::string aWord; std::cin>>aWord;)//只要还有输入
	{
		mymap[aWord]++;
	}
	std::for_each(mymap.begin(),mymap.end(),print());//调用print结构体，并且调用其中()函数/成员，即调用函数入口地址
	return 0;
}
