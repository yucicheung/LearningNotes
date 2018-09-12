#include<string>
#include<iostream>
#include<cstdio>
#include<cassert>

using namespace std;

int main()
{
    //string对象的size只记录字符串的有效长度，不记录最末的/0
    string str{"Hello"};
    cout<<str.size()<<endl;

    //常量字符串存放在单独的内存区域
    //指向常量字符串的几个指针会指向同一个内存地址
    char* pstr1 = "HelloWorld";
    char* pstr2 = "HelloWorld";
    assert(pstr1==pstr2);

    //存储常量字符串的字符串数组都有新开辟的空间
    char str1[]= "HelloWorld";
    char str2[]= "HelloWorld";
    assert(str1!=str2);
    printf("%d\n",pstr1);
    printf("%d\n",&str1[0]);


    return 0;
}
