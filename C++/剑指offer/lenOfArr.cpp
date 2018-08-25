#include<stdio.h>
#define ARR_LEN(ar) sizeof(ar)/sizeof(ar[0])
#define maxn 1010

int a[maxn];
int main()
{
    printf("%d\n",ARR_LEN(a));
    return 0;
}
