#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double a=123.456,b=3.14159,c=-3214.67;
	//set style influencing all upcoming cout
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<setiosflags(ios::right);
	// output value one by one
	cout<<setw(9)<<a<<'\n';
	cout<<setw(9)<<b<<'\n';
	cout<<setw(9)<<c<<endl;
	return 0;
}
