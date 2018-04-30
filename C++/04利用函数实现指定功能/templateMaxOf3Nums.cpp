#include<iostream>
using namespace std;
template <typename T>//<class T>

T max(T x,T y,T z)
{
T m;
m = (x>y?x:y);
return (m>z?m:z);
}

int main()
{
int i1=185,i2=-76,i3=567;
double d1=56.87,d2=90.23,d3=-3214.78;
long l1=67854,l2=-912546,l3=673456;
cout<<max(i1,i2,i3)<<endl;
cout<<max(d1,d2,d3)<<endl;
cout<<max(l1,l2,l3)<<endl;
return 0;
}
