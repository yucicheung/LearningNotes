//��������֮ǰʹ�õ��Ƕ��������ĸ���
//����ѭ������ӦΪ1�ĸ���

//�����ģ�������ÿռ任ʱ��ķ���
//һ���ֽڶ�Ӧ�Ĵ洢�ķ�Χ������0-255���������ҪƵ��ʹ��ʱ
//����һ��256�ߴ�����鼴��
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
