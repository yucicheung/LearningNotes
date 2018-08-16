#include<cstdio>
#include<cmath>

int main()
{
    int n;
    const double pi = acos(-1);
    //printf("%f",pi);
    scanf("%d",&n);
    printf("%f\n%f\n",sin(n/180.0*pi),cos(n/180.0*pi));
    return 0;
}
