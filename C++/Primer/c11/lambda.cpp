/*
lambda������ʹ��
typedef�Ļ���ʹ��
*/
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100;
int arri[maxn]{4,5,2,3,7,8};

typedef uint32_t myint;
int main()
{
    //[]�б�ʾ�������ֵ
    //lambda���ʽ���Ҫʹ�ú������ⶨ��ı���������Ҫ��֮���в���
    //�����[]��ʾ�������ú�����ı���
    //[=]��ʾֵ����
    //[&]��ʾ���ò���
    sort(arri,arri+6,[](int x,int y){return x>y;});
    for(int i:arri)printf("%d\n",i);
    myint a=2;
    printf("%d",a);
    return 0;
}
