#include<stdio.h>
#include<math.h>
#define MAX 316
#define S 0.00001

int main()
{
    unsigned int n,m,kase=0;
    while(scanf("%d%d",&n,&m)==2 && n && m)
    {
        printf("%d %d\n",n,m);
        if(m>MAX)m=MAX;
        kase++;
        double s=0;
        if(n>MAX)s=S;
        else{
                for(unsigned int i=n;i<=m;i++)
                {
                    s+=(double)1/(i*i);
                    printf("%f\n",s);
                }
        }

        printf("Case %d: %.5f\n",kase,s);
    }
    return 0;
}
