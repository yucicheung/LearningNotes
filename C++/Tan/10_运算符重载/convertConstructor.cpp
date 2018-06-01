#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(){real=0,imag=0;};
	Complex(double r,double i):real(r),imag(i){};
	Complex(double r):real(r),imag(0){};//convert constructor allowing for type double to used as class
	operator double(){return real;};//type converter allowing for class to be used as type double
	friend ostream& operator<< (ostream&,Complex&);
	//void display();
private:
	double real;
	double imag;
};

/*
operator double()
{
return real;
}
*/

ostream& operator<<(ostream& output,Complex& c)
{
output<<'('<<c.real<<'+'<<c.imag<<'i'<<')'<<endl;
return output;
}

int main()
{
Complex a[3]={Complex(1,2),Complex(-1,-2),Complex(9.5)};
Complex b(-3,6);
double outAns=1;

cout<<" allow class to be used as double"<<endl;
cout<<b;
cout<<(outAns=b+10)<<endl;
cout<<(double(b)+outAns)<<endl;

cout<<" allow double to be used as class"<<endl;
cout<<a[2];
a[2] = a[2]+10.5;
cout<<a[2];
return 0;
}
