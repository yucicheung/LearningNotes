/*
���⣺���N!�Ķ����Ʊ�ʾ�����λ1��λ�ã��������N=3��N!=6=1010B=101*2^1�����λ�ڵڶ�λ
�������ж�N!�к���������2�ĸ���n�����λ��1��n+1λ
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
