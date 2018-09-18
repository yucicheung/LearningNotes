/*
问题：求解N!的二进制表示中最低位1的位置，比如给定N=3，N!=6=1010B=101*2^1的最低位在第二位
分析：判断N!中含有质因数2的个数n，最低位的1在n+1位
*/
#include<iostream>
using namespace std;

int lowestOne(int input)
{
    int ret=0;
    while(input)
    {
        input>>=1;
        ret+=input;
    }
    return ret;
}

int main()
{
    int input;
    while(cin>>input)
        cout<<lowestOne(input)<<endl;
    return 0;
}
