//��ϰvector��ʹ��
/*
������n��ľ�飬���λ0~n-1

��ľ�����4�ֲ�����
1. move a onto b: ��a��b�Ϸ�ľ���λ���ٰ�a����b����
2. move a over b: ��a�Ϸ�ľ���λ���ٰ�a����b�Ѷ���
3. pile a onto b: ��b�Ϸ�ľ���Ϊ����a���Ϸ�ľ������b����
4. pile a over b: ��a�������ľ����������b����ľ��ѵĶ���
����quitʱ��ֹ���룬a��b��ͬ��Ϊ�Ƿ������ԡ�

���룺
1. ����һ��n��
2. ��������ָ�������Ӧָ�
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int maxn=10;
vector<int> piles[maxn];
int n;

//��λԪ�����ڵĶѣ����ڶ��ϵĸ߶�
void locate_pile(const int mem,int &p,int&h)
{
    for(int i=0;i<n;i++)
    {
        for(size_t j=0;j<piles[i].size();j++)
        {
            if(piles[i][j]==mem){p=i;h=j;}
        }
    }
}

//��ָ����ָ���߶����ϵ�Ԫ��ȫ����λ
void clear_above(const int h,const int p)
{
    for(size_t j=h+1;j<piles[p].size();j++)
    {
        int k=piles[p][j];
        piles[k].push_back(k);
    }
    piles[p].resize(h+1);
}

//��ǰ��ѵ��������ݶ������ں���ѵĶ���
void pile_onto(const int p,const int h,const int p2)
{
    int k;
    for(size_t j=h;j<piles[p].size();j++)
    {
        k=piles[p][j];
        piles[p2].push_back(k);
    }
    piles[p].resize(h);
}

void print_piles()
{
    for(int i=0;i<n;i++)
    {
        cout<<"piles "<<i<<":";
        for(size_t j=0;j<piles[i].size();j++)
            cout<<piles[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    string op1,op2;
    int a,b;
    cin>>n;
    for(int i=0;i<n;i++)piles[i].push_back(i);
    print_piles();
    while(cin>>op1 && op1!="quit" &&cin>>a>>op2>>b)
    {
        int ha,pa,hb,pb;
        locate_pile(a,pa,ha);
        locate_pile(b,pb,hb);
        if(pa==pb)continue;
        if(op1=="move")clear_above(ha,pa);
        if(op2=="onto")clear_above(hb,pb);
        pile_onto(pa,ha,pb);
        print_piles();
    }
    return 0;
}
