#include<stdio.h>
#include<string.h>
#define maxn 10010
char str[maxn];

int main()
{
    int num[10]={};
    char c;
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        int index= str[i]-'0';
        num[index]++;
    }
    for(int i=0;i<=9;i++)
        printf("%d\n",num[i]);
    return 0;
}
