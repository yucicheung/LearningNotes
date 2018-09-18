#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void disp_vec(const vector<int> iVec)
{
    for(auto i:iVec)
        cout<<i<<endl;
    cout<<endl;
}

int main()
{
    //使用make_heap算法产生堆
    vector<int> iVec{45,67,32,98,12,4};
    make_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);
    iVec.push_back(56);
    disp_vec(iVec);
    make_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);

    //pop_heap算法调用
    pop_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);
    pop_heap(iVec.begin(),iVec.end()-1);
    disp_vec(iVec);
    iVec.pop_back();
    iVec.pop_back();

    //sort_heap算法调用
    sort_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);

    return 0;
}
