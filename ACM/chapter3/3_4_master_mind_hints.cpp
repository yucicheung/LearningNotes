/*
输入一行一个数字n，表示序列长度
接下来一行是正确答案
接下来若干行是猜测答案，长度均为n
输出全0时结束数据输出,正常输入数据不会是0
输出(A,B)，其中A是对齐的数字个数
B是本来可以同位对齐但是位置错位的数字个数
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
