#include<iostream>
#include<iterator>
using namespace std;

template<typename T>
T sum(T* pbeg,T* pend)
{
    T ans = 0;
    for(auto p=pbeg;p!=pend;p++)
        ans=ans+(*p);
    return ans;
}

int main()
{
    double a[10]={1.2,2.,3,4,5,6,7,8,9,10};
    cout<<(sum(a,a+10))<<endl;
    return 0;
}
