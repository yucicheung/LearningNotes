/*
���������ÿ�а������ɸ�(����һ��)�Կո����������
���ÿ������������֮��
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
