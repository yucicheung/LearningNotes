/*
���x����x�ĸ�������֮�͵õ�y,��˵x��y������Ԫ
����n(1<=n<=100000)
�����С����Ԫ���޽����0

�ò��:��ö������100000�ڵ��������������������key��value����arr[key]�м���
�����ڵ�ֵΪ0�����ڵĽ��бȽ�����Сֵ
*/
#include<stdio.h>
#include<string.h>
#define maxn 100010
int ans[maxn];

int main()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=100000;i++)
    {
        int y=i,x=i;
        while(x>0){y+=(x%10);x=x/10;}
        if(ans[y]==0 || i<ans[y])ans[y]=i;
    }
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
