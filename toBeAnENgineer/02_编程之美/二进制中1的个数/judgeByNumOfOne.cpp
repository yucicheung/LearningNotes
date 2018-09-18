//方法三：之前使用的是二进制数的个数
//现在循环次数应为1的个数

//方法四：查表法，用空间换时间的方法
//一个字节对应的存储的范围正好在0-255，当查表需要频繁使用时
//开辟一个256尺寸的数组即可
#include<iostream>
using namespace std;

int count_one(int byte)
{
    int num=0;
    while(byte)
    {
        byte &= byte -1;
        num++;
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
