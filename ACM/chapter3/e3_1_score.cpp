/*
����һ����O��X��ɵĴ�(1-80)
ÿ��O�ĵ÷�ΪĿǰ�������ֵĸ���,ÿ��X�÷�Ϊ0
����Ϊ��OOXXOXXOOO
�÷�Ϊ��1+2+0+0+1+0+0+1+2+3
*/
#include<stdio.h>
#include<string.h>

#define maxn 90
char str[maxn];
int ans[maxn];
int main()
{
    while(scanf("%s",str)==1)
    {
        int val=0;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='O')val++;
            else val=0;
            ans[i]=val;
        }
        for(int i=0;i<strlen(str)-1;i++)
            printf("%d+",ans[i]);
        printf("%d\n",ans[strlen(str)-1]);
    }
    return 0;
}
