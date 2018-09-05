#include<iterator>
#include<vector>
#include<iostream>

#define maxn 1010
using namespace std;

int ia[maxn];
int main()
{

    ia[0]=1;
    auto pbeg= begin(ia);
    auto plast= end(ia);
    while(pbeg!=plast&&(*pbeg)){cout<<*pbeg<<endl;++pbeg;}

    decltype(ia) ib={1,2,23,4};
    vector<int> ivec(begin(ib),end(ib));
    vector<int> ivec_(ib,ib+4);

    return 0;

}
