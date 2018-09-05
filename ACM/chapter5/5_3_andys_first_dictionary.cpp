/*
可以使用set的对象必须已经定义有“小于”运算符(升序排列)
set存储已经排好序的元素集合

需要注意的点：
1. 字母要统一大小写
2. 标点符号需要进行消除,用空格替换
3. stringstream是用空格区分每个输入
4. 使用命令行+文件进行输入比较方便。win下命令是type

*/
#include<set>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
set<string> dict;

int main()
{
    string str;
    while(cin>>str)
    {
        for(int i=0;i<str.length();i++)
        {
            if(isalpha(str[i]))str[i]=tolower(str[i]);
            else str[i]=' ';//remove punctuation
        }
        string word;
        stringstream ss(str);
        while(ss>>word)dict.insert(word);
    }
    for(auto word:dict)cout<<word<<endl;//word为string类型
    return 0;
}
