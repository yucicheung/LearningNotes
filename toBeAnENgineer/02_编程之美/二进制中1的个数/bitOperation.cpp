//方法2：用每个数的最后一位判断bit1的个数
//位操作比取余数要高效很多
#include<iostream>
using namespace std;

int count_one(int byte)
{
    int num=0;
    while(byte)
    {
        num += byte&0x01;
        byte>>=1;
    }
    return num;
}
int main()
{
    int byte;
    while(cin>>byte)
        cout<<count_one(byte)<<endl;
    return 0;
}
