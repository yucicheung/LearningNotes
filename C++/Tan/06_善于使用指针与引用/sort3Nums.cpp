#include<iostream>
using namespace std;
void swap(int & a,int&b)
{int tmp;tmp=a,a=b,b=tmp;}

void sort(int&a,int&b,int&c)
{
if (a>b) swap(a,b);
if(a>c) swap(a,c);
if(b>c) swap(b,c);
}

int main()
{
int i=56,j=-1,k=0;
sort(i,j,k);
cout<<"i="<<i<<",j="<<j<<",k="<<k<<endl;
return 0;
}
