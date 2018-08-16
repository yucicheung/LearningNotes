#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    const double pi = acos(-1.0);//cos(pi)=-1
    printf("%f\n",pi);
    double r,h,s1,s2,s;
    scanf("%lf%lf",&r,&h);
    s1 = pi*r*r;
    s2 = 2.0*pi*r*h;
    s = s2+ 2.0*s1;
    printf("%f",s);
    system("pause");
    return 0;
}
