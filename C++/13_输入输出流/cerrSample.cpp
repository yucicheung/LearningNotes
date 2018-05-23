//using one-quadratic equation as example
//to show the usage of cerr
//which output the defined error message according to your input
//Notice that it can not be redirected

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
float a,b,c,disc;
cout<<"please input a,b,c:";
cin>>a>>b>>c;
//if condition satisfied
//error message should be printed on screen
if(a==0) cerr<<"a is equal to 0,error!"<<endl;
else
	if(disc=(b*b-4*a*c)<0) cerr<<"b*b-4*a*c<0"<<endl;
	else
		{
		cout<<"x1="<<(-b+sqrt(disc))/(2*a)<<endl;
		cout<<"x2="<<(-b-sqrt(disc))/(2*a)<<endl;
		}
return 0;
}
