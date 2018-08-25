/*
已知C,H,O,N的原子量分别为12.01,1.008,16.00,14.01
求输入分子式的分子量(保留三位精度)
*/
#include<stdio.h>
#include<string.h>
#include<map>
#define maxn 80

using namespace std;
char str[maxn];

int main()
{

    map<char,double> map_={{'C',12.01},{'H',1.008},{'O',16.00},{'N',14.01}};
    while(scanf("%s",str)==1)
    {
        int i =0;
        double ans=0,weight=0;
        int num=0,sum=0;
        while(i<strlen(str))
        {
            if(isalpha(str[i]))
            {weight = map_[str[i++]];sum=1;}
            if(isdigit(str[i]))
            {
                sum=0;
                while(isdigit(str[i]))
                {num=str[i++]-'0';sum=sum*10+num;}
            }
            ans+=(sum*weight);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
