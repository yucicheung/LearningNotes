#include<stdio.h>

#define EPS 1e-5
int main()
{
    double a;
    while(scanf("%lf",&a)==1)
    printf("%.2f\n",a+EPS);
    return 0;
}
