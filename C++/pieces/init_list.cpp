/*
��ʼ���б�ĵ���,��ʼ���б���{}Ȧ����б�
��C11�У��������еĶ��󶼿��Ա��б��ʼ��

��ʼ���б��ԭ����
`std::initializer_list<T> init_list`
���������{}ȥ��ʼ��auto�����ᵼ�����벻���Ľ��
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

//������Ҫ������main������
vector<int> test_function()
{
    return {1,2,3};
}
void test_function2(vector<int>){}


int main()
{
    auto p=new vector<string>{"foo","bar"};
    map<int,string> m={{1,"one"},{2,"two"}};

    //��ʽ��ʼ���б�
    test_function2({1,2,3});

    //������ʼ���б�
    for(auto i:{1,2,3}){printf("%d\n",i);}


    return 0;
}
