/*
����һ��һ������n����ʾ���г���
������һ������ȷ��
�������������ǲ²�𰸣����Ⱦ�Ϊn
���ȫ0ʱ�����������,�����������ݲ�����0
���(A,B)������A�Ƕ�������ָ���
B�Ǳ�������ͬλ���뵫��λ�ô�λ�����ָ���
*/
#include<stdio.h>
#define maxn 1010

int a[maxn];
int b[maxn];

int main()
{
    int n,kase=0;
    while(scanf("%d",&n)==1&&n)
    {
        kase++;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        printf("Game %d:\n",kase);
        for(;;)
        {
            int A=0,B=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&b[i]);
                if(b[i]==a[i])A++;
            }
            if(!b[0])break;
            for(int i=1;i<=9;i++)
            {
                int c1=0,c2=0;
                for(int j=0;j<n;j++)
                {
                    if(a[j]==i)c1++;
                    if(b[j]==i)c2++;
                }
                B+=((c1<c2)?c1:c2);
            }
            printf("    (%d,%d)",A,B-A);
        }
    }
    return 0;
}
