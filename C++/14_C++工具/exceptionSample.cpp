#include<iostream>
#include<cmath>

using namespace std;

int main()
{
double triangle(double,double,double);
double a,b,c;
cin>>a>>b>>c;
try
{
while(a>0&&b>0&&c>0)
	{
	cout<<triangle(a,b,c)<<endl;
	cin>>a>>b>>c;
	}
}
catch(double)
	{
	cout<<"This is not a triangle."<<endl;
	}
return 0;
}

double triangle(double a,double b,double c)
{
double area;
double s=(a+b+c)/2;
if (!(a+b>c&&a+c>b&&b+c>a)) throw a;
area=sqrt(s*(s-a)*(s-b)*(s-c));
return area;
}
