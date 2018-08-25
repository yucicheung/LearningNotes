#include<stdio.h>
#define INF 1000000000

int main()
{
    int kase=0,x=0,n=0;
    while(scanf("%d",&n)==1&&n)
    {
        int s =0,max_=-INF,min_=INF;
        kase++;
        for(int i =0;i<n;i++)
        {
            scanf("%d",&x);
            s+=x;
            if(x>max_) max_=x;
            if(x<min_) min_=x;
        }
        printf("Case %d: %d %d %.3f\n\n",kase,min_,max_,(double)s/n);

    }
    return 0;

}
