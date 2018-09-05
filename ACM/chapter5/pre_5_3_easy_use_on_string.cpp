/*
输入的数据每行包含若干个(至少一个)以空格隔开的整数
输出每行中所有整数之和
*/
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        int x,sum=0;;
        stringstream sstr(str);
        while(sstr>>x)sum+=x;
        cout<<sum<<endl;
    }
    return 0;
}
