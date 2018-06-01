#include<iostream>
using namespace std;
void swap(int& a,int&b)
{int tmp;
tmp=a;
a=b;
b=tmp;
}

int main()
{
int i=3,j=5;
cout<<"i="<<i<<",j="<<j<<endl;
swap(i,j);
cout<<"i="<<i<<",j="<<j<<endl;
return 0;
}
