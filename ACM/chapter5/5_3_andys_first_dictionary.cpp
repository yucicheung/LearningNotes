/*
����ʹ��set�Ķ�������Ѿ������С�С�ڡ������(��������)
set�洢�Ѿ��ź����Ԫ�ؼ���

��Ҫע��ĵ㣺
1. ��ĸҪͳһ��Сд
2. ��������Ҫ��������,�ÿո��滻
3. stringstream���ÿո�����ÿ������
4. ʹ��������+�ļ���������ȽϷ��㡣win��������type

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
    for(auto word:dict)cout<<word<<endl;//wordΪstring����
    return 0;
}
