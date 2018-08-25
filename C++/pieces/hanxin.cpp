#include<stdio.h>

int main()
{
    int n3=0,n5=0,n7=0,kase=0,s=0;
    while(scanf("%d%d%d",&n3,&n5,&n7)==3)
    {
        kase++;
        int flag=0;
        for(int i =0;(s=i*7+n7)<=100;i++)
        {
            if(s%5==n5&&s%3==n3)
            {
                printf("Case %d: %d\n",kase,s);
                flag = 1;
                break;
            }
        }
        if(flag==0)printf("Case %d: No answer\n",kase);
    }
    return 0;
}
