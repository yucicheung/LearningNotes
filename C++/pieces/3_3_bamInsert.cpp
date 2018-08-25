#include<string.h>
#include<stdio.h>
#define maxn 30
#define maxm 50
int a[maxn][maxm];

int main()
{
    int n,s=0,x,y;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    s=a[x=0][y=n-1]=1;
    while(s<n*n)
    {
        // 注意数组下标越界问题
        while(x<n-1 && !a[x+1][y])a[++x][y]=++s;
        while(y>0 && !a[x][y-1])a[x][--y]=++s;
        while(x>0 && !a[x-1][y])a[--x][y]=++s;
        while(y<n-1 && !a[x][y+1])a[x][++y]=++s;
    }
    for(int i =0;i<=n*n-1;i++)
    {
        printf("%4d",a[i/n][i%n]);
        if((i+1)%n==0)printf("\n");
    }
    return 0;
}
