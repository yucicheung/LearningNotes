#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
double a,b,c;
cout<<"Please enter a,b,c:";
cin>>a>>b>>c;
if((a+b>c)&&(a+c>b)&&(b+c>a))
	{
	double s,area;//define here helps save space
	s = (a+b+c)/2;
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<setiosflags(ios::fixed)<<setprecision(4);
	cout<<"area="<<area<<endl;
	}
else
	cout<<"This is not a Triangle."<<endl;
return 0;
}
