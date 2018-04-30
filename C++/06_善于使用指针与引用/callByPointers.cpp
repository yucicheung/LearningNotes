#include<iostream>
using namespace std;
int max(int a, int b)
{
return (a>b)?a:b;
}
int main()
{
int a =10,b=8;
int (*p)(int,int);
p=max;
cout<<p(a,b)<<endl;
return 0;
}
