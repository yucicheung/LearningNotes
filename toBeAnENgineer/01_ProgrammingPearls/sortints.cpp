#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int> input;
    int i;
    while(cin>>i)
        input.insert(i);
    for(auto i:input)
        cout<<i<<endl;
    return 0;
}
