#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c,x1,x2;
	cin>>a>>b>>c;
	x1 = (-sqrt(b*b-4*a*c)-b)/(2*a);
	x2 = (sqrt(b*b-4*a*c)-b)/(2*a);
	cout<<"x1="<<x1<<','<<"x2="<<x2<<endl;
}
