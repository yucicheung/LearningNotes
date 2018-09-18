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
    //ʹ��make_heap�㷨������
    vector<int> iVec{45,67,32,98,12,4};
    make_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);
    iVec.push_back(56);
    disp_vec(iVec);
    make_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);

    //pop_heap�㷨����
    pop_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);
    pop_heap(iVec.begin(),iVec.end()-1);
    disp_vec(iVec);
    iVec.pop_back();
    iVec.pop_back();

    //sort_heap�㷨����
    sort_heap(iVec.begin(),iVec.end());
    disp_vec(iVec);

    return 0;
}
