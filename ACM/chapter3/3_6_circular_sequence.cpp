/*
长度为n的环状串有n中表示方法，字典序(字符串在字典中的顺序)最小的表示称为“最小表示”

输入长度为n(n<=100)的环状DNA串(A,C,G,T)的一种表示法，输出该环状串的最小表示

分析：
对于长度固定的DNA串，只需要通过两种排序中第一个不同的字符进行比较处理即可。
*/
#include<stdio.h>
#include<string.h>
#define maxn 105
char str[maxn];

bool isLess(const char* s,int p,int q)
{
    //TODO: compare dict order
    int len = strlen(s);
    for(int i=0;i<len;i++)
        if(s[(i+p)%len]!=s[(i+q)%len])
        return s[(i+p)%len]<s[(i+q)%len];
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len= strlen(str);
        int ans=0;
        for(int i=1;i<len;i++)
        {
            if(isLess(str,i,ans))ans =i;
        }
        for(int i=0;i<len;i++)
            putchar(str[(i+ans)%len]);
        putchar('\n');
    }
    return 0;
}
