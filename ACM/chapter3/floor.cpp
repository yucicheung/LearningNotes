#include<math.h>
#include<stdio.h>

int main()
{
    float f;
    while(scanf("%f",&f)==1)
    {
        printf("%.2f\n",f+0.0005);
    }
    return 0;
}
