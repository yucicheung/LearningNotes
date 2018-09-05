/*
初始化列表的迭代,初始化列表是{}圈起的列表
在C11中，几乎所有的对象都可以被列表初始化

初始化列表的原型是
`std::initializer_list<T> init_list`
所以如果用{}去初始化auto变量会导致意想不到的结果
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

//函数不要定义在main函数中
vector<int> test_function()
{
    return {1,2,3};
}
void test_function2(vector<int>){}


int main()
{
    auto p=new vector<string>{"foo","bar"};
    map<int,string> m={{1,"one"},{2,"two"}};

    //隐式初始化列表
    test_function2({1,2,3});

    //迭代初始化列表
    for(auto i:{1,2,3}){printf("%d\n",i);}


    return 0;
}
