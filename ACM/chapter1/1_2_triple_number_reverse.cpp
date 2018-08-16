#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    //printf("%d%d%d",n%10,n/10%10,n/100);
    int m = (n%10)*100+(n/10%10)*10+(n/100);
    printf("%03d",m);   //input 250, return 052
    return 0;
}
