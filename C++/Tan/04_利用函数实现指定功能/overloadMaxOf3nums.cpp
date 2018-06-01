#include<iostream>
using namespace std;

int main()
{
int max(int,int,int);
double max(double,double,double);
long max(long,long,long);
int i1,i2,i3;
//int i5,i6;
double d1,d2,d3;
long l1,l2,l3;
cout<<"Input 3 ints:";
cin>>i1>>i2>>i3;
cout<<max(i1,i2,i3)<<endl;
cout<<"Input 3 decimal numbers:";
cin>>d1>>d2>>d3;
cout<<max(d1,d2,d3)<<endl;
cout<<"Input 3 long integars:";
cin>>l1>>l2>>l3;
cout<<max(l1,l2,l3)<<endl;
//cout<<"Input 2 integars:";
//cin>>i5>>i6;
//cout<<max(i5,i6)<<endl;
return 0;
}

int max(int x,int y,int z)
{
int m;
m=(x>y?x:y);
return (m>z?m:z);
}
/*
int max(int x,int y)
{
return (x>y?x:y);
}
*/
double max(double x,double y,double z)
{
double m;
m = (x>y?x:y);
return (m>z?m:z);
}

long max(long x,long y,long z)
{
long m;
m=(x>y?x:y);
return (m>z?m:z);
}
