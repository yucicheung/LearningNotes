#include<string>
#include<iostream>
#include<cstdio>
#include<cassert>

using namespace std;

int main()
{
    //string�����sizeֻ��¼�ַ�������Ч���ȣ�����¼��ĩ��/0
    string str{"Hello"};
    cout<<str.size()<<endl;

    //�����ַ�������ڵ������ڴ�����
    //ָ�����ַ����ļ���ָ���ָ��ͬһ���ڴ��ַ
    char* pstr1 = "HelloWorld";
    char* pstr2 = "HelloWorld";
    assert(pstr1==pstr2);

    //�洢�����ַ������ַ������鶼���¿��ٵĿռ�
    char str1[]= "HelloWorld";
    char str2[]= "HelloWorld";
    assert(str1!=str2);
    printf("%d\n",pstr1);
    printf("%d\n",&str1[0]);


    return 0;
}
