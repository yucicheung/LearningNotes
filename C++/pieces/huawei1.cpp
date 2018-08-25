#include<stdio.h>
#include<math.h>
unsigned int price1(unsigned int n,unsigned int m)
{
    unsigned int sum = m*n;
    if(n>=3)sum*=0.7;
    if(sum<5000)sum+=1000;
    printf("s1:%d\n",sum);
    return sum;
}

unsigned int price2(unsigned int n, unsigned int m)
{
    unsigned int sum=m*n;
    unsigned int i= (unsigned int)sum/1000;
    sum -=(i*200);
    if(sum<9900) sum+=600;
    printf("s2:%d\n",sum);
    return sum;
}

int main()
{
    unsigned int n;
    float m;
    while(scanf("%d %f",&n,&m)==2)
    {
        printf("%f\n",m);
        unsigned int m_=(unsigned int)(floor((m+0.005)*100));
        printf("%d\n",m_);
        unsigned int s1= price1(n,m_);
        unsigned int s2 = price2(n,m_);
        if(s1==s2)printf("0\n");
        else if(s1<s2) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
