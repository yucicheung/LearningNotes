/*
����Ϊn�Ļ�״����n�б�ʾ�������ֵ���(�ַ������ֵ��е�˳��)��С�ı�ʾ��Ϊ����С��ʾ��

���볤��Ϊn(n<=100)�Ļ�״DNA��(A,C,G,T)��һ�ֱ�ʾ��������û�״������С��ʾ

������
���ڳ��ȹ̶���DNA����ֻ��Ҫͨ�����������е�һ����ͬ���ַ����бȽϴ����ɡ�
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
