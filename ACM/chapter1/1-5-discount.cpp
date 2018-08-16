#include<stdio.h>

int main()
{
    int n;
    double s;
    scanf("%d",&n);
    s = n*95.0;
    if(s>300) s*=0.85;
    printf("%.2f",s);
    return 0;
}
