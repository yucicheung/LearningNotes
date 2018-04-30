#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int a[10],*p=a,i;
for(i=0;i<10;i++) *(p+i)=i;
for(;p<(a+10);p++) cout<<*p<<endl;
p = &a[1];//reference is always legal
for(i=0;i<10;i++) cout<<p[i]<<endl;//even exceed range of array
return 0;
}
