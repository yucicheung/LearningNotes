#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int ia[]{1,2,3,4};
    for(auto &x:ia)
        x*=2;
    for(auto &x:ia)
        cout<<x<<endl;

    string str{"12345"};
    cout<<"string size:"<<str.size()<<endl;
    for(const auto& astr : str)
        cout<<astr<<endl;

    vector<string> svec{"12345","abc","de"};
    cout<<"vector size:"<<svec.size()<<endl;
    for(const auto& avec:svec)
        cout<<avec<<endl;

    return 0;
}
