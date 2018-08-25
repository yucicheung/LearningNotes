#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxn 1010
using namespace std;
int a[maxn];

int main()
{
    int n,k,first=1;//first变量避免输出多余空格
    scanf("%d %d",&n,&k);
    memset(a,0,sizeof(a));//数组内部的随机值全部置为0
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++){
            if(i%j==0)a[i]=!a[i];
        }
    }
    for(int i =1;i<=n;i++)
    {
        if(a[i])
        {
            if(first)first=0;
            else printf(" ");
            printf("%d",i);
        }
    }
    return 0;
}
