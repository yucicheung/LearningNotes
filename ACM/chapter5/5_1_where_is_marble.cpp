/*
����һ�����֣�����n��q
����������1�У�����n�����֣���ʾʯ���ϵ�����
������һ�У�����Ҫ���ҵ�q�����֣�ÿ������ش��ܷ���ڸ����֣�������ڣ��ش����Ŀ����ʯ��д��
��n=0ʱ��ʾ��������
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=10010;
int marble[maxn];

int main()
{
    int n,q,x,kase=0;
    while(scanf("%d%d",&n,&q)==2&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&marble[i]);
        sort(marble,marble+n);
        for(int i=0;i<n;i++)cout<<marble[i]<<endl;
        kase++;
        cout<<"CASE# "<<kase<<":"<<endl;
        while(q--)
        {
            scanf("%d",&x);
            auto index = lower_bound(marble,marble+n,x);
            if(*index==x)cout<<x<<" found at "<<(index-marble+1)<<endl;
            else cout<<x<<" not found"<<endl;
        }
    }
    return 0;
}
