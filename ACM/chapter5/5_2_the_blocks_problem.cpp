//练习vector的使用
/*
从左到右n个木块，编号位0~n-1

对木块进行4种操作：
1. move a onto b: 把a及b上方木块归位，再把a放在b上面
2. move a over b: 把a上方木块归位，再把a放在b堆顶部
3. pile a onto b: 把b上方木块归为，把a及上方木块摞在b上面
4. pile a over b: 把a及上面的木块整体摞在b所有木块堆的顶部
遇到quit时终止输入，a与b在同堆为非法，忽略。

输入：
1. 输入一个n。
2. 输入上述指令，做出相应指令。
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int maxn=10;
vector<int> piles[maxn];
int n;

//定位元素所在的堆，和在堆上的高度
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

//将指定堆指定高度以上的元素全部归位
void clear_above(const int h,const int p)
{
    for(size_t j=h+1;j<piles[p].size();j++)
    {
        int k=piles[p][j];
        piles[k].push_back(k);
    }
    piles[p].resize(h+1);
}

//将前面堆的所有内容都放置在后面堆的顶上
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
