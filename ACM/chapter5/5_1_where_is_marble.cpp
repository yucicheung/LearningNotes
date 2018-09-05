/*
输入一行数字，包含n和q
接下来包含1行，包含n个数字，表示石碑上的数字
接下来一行，包含要查找的q个数字，每个问题回答受否存在该数字，如果存在，回答在哪块大理石上写着
当n=0时表示结束输入
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=10010;
int marble[maxn];

int main()
{
    int n,q,x,kase=0;
    while(scanf("%d%d",&n,&q)==2&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&marble[i]);
        sort(marble,marble+n);
        for(int i=0;i<n;i++)cout<<marble[i]<<endl;
        kase++;
        cout<<"CASE# "<<kase<<":"<<endl;
        while(q--)
        {
            scanf("%d",&x);
            auto index = lower_bound(marble,marble+n,x);
            if(*index==x)cout<<x<<" found at "<<(index-marble+1)<<endl;
            else cout<<x<<" not found"<<endl;
        }
    }
    return 0;
}
