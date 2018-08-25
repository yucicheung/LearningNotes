//#define LOCAL
#include<stdio.h>

int main()
{
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif // LOCAL
    int max_,min_,x,n=0,s=0;
    scanf("%d",&x);
    min_=max_=x;
    while(scanf("%d",&x)==1)
    {
        s+=x;
        if(x<min_) min_=x;
        if(x>max_) max_=x;
        n++;
    }
    printf("%d %d %.3f",min_,max_,(double)s/n);
    return 0;
}

