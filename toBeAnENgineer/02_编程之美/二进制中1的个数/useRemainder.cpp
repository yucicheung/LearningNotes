//����1���������ж�һ���ֽ���1�ĸ���
#include<iostream>
using namespace std;

int count_one(uint32_t n)
{
    int num=0;
    while(n)
    {
        num += n%2;
        n /= 2;
    }
    return num;
}

int main()
{
    uint32_t toDetermine;
    while(cin>>toDetermine)
        cout<<"The total count of 1:"<<count_one(toDetermine)<<endl;
    return 0;
}
