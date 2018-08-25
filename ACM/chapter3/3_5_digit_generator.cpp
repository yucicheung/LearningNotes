/*
如果x加上x的各个数字之和得到y,就说x是y的生成元
输入n(1<=n<=100000)
输出最小生成元，无解输出0

用查表法:先枚举所有100000内的所有正整数，用序号做key，value存在arr[key]中即可
不存在的值为0，存在的进行比较求最小值
*/
#include<stdio.h>
#include<string.h>
#define maxn 100010
int ans[maxn];

int main()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=100000;i++)
    {
        int y=i,x=i;
        while(x>0){y+=(x%10);x=x/10;}
        if(ans[y]==0 || i<ans[y])ans[y]=i;
    }
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
