//����2����ÿ���������һλ�ж�bit1�ĸ���
//λ������ȡ����Ҫ��Ч�ܶ�
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
