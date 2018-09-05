#include<stdio.h>
#define maxn 1010


int main()
{
    int a[maxn]={};
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
