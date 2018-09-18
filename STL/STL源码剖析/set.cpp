#include<iostream>
#include<set>
using namespace std;

int main()
{
    int i;
    int ia[5] = {0,1,2,3,4};
    set<int> iSet(ia,ia+5);
    cout<<iSet.size()<<endl;
    iSet.insert(3);
    cout<<iSet.count(3)<<endl;

    iSet.erase(4);

    for(auto iter_content:iSet)
    {
        cout<<iter_content<<endl;
    }

    //注意set自带的find算法会比algorithm中的算法更加高效
    auto iter = iSet.find(3);
    if(iter!=iSet.end())
        cout<<(*iter)<<" Found"<<endl;

    //一定要注意的是set的迭代器是const型
    //不允许通过*iter改变其内容值
    //*iter = 9; Error!
    return 0;
}
