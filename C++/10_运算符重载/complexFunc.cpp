#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(){real=0;imag=0;}
	Complex(double r,double i){real=r,imag=i;}
	Complex complex_add(Complex&);
	void display();
private:
	double real;
	double imag;
};

Complex Complex::complex_add(Complex& a)
{
Complex b;
b.real = real + a.real;
b.imag = imag + a.imag;
return b;
}

void Complex::display()
{
cout<<real<<'+'<<imag<<'i'<<endl;
}

int main()
{
Complex a(1,2),b(-3,4);
Complex c = a.complex_add(b);
c.display();
return 0;
}
