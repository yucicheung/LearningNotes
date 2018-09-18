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

    //ע��set�Դ���find�㷨���algorithm�е��㷨���Ӹ�Ч
    auto iter = iSet.find(3);
    if(iter!=iSet.end())
        cout<<(*iter)<<" Found"<<endl;

    //һ��Ҫע�����set�ĵ�������const��
    //������ͨ��*iter�ı�������ֵ
    //*iter = 9; Error!
    return 0;
}
