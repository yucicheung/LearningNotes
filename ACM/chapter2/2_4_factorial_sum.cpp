#include<stdio.h>
#include<time.h>

int main()
{
    const int MOD = 1000000;
    int n;
    int fac = 1;
    int sum =0;
    scanf("%d",&n);
    if(n>25)n=25;   //25以后的数目对结果没有影响
    for(int i=1;i<=n;i++)
    {
        fac = (fac*i)%MOD;
        printf("%d:%d\n",i,fac);
        sum = (sum+fac)%MOD;
    }
    printf("%d\n",sum);
    printf("Time used = %.6fs",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
