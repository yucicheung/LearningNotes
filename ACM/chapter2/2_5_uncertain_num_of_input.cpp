#include<stdio.h>

int main()
{
    int x,max_,min_,s=0,n=0;
    scanf("%d",&x);
    s=min_=max_=x;
    n++;
    while(scanf("%d",&x)==1)
    {
        if(x<min_)min_=x;
        if(x>max_)max_=x;
        n++;
    }
    printf("min=%d\nmax=%d\nave=%.3f\n",min_,max_,s/3.0);
    return 0;
}
