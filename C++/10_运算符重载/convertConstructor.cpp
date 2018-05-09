#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(){real=0,imag=0;};
	Complex(double r,double i):real(r),imag(i){};
	operator double();
	friend ostream& operator<< (ostream&,Complex&);
	//void display();
private:
	double real;
	double imag;
};

operator double()
{
return real;
}

ostream& operator<<(ostream& output,Complex& c)
{
output<<'('<<c.real<<'+'<<c.imag<<'i'<<')'<<endl;
return output;
}

int main()
{
Complex a(1,2);
double d1,outAns;
cout<<a;
cout<<(outAns=a+d1);
return 0;
}
