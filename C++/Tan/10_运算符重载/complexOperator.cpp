#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(){real=0,imag;}
	Complex(int r,int i):real(r),imag(i){};
	Complex operator + (Complex&);
	void display();
private:
	double real;
	double imag;
};

Complex Complex::operator +(Complex& a)
{
Complex c;
c.real = real + a.real;
c.imag = imag + a.imag;
return c;
}

void Complex::display()
{
cout<<real<<'+'<<imag<<'i'<<endl;
}

int main()
{
Complex a(1,2),b(3,4),c;
c = a+b;
c.display();
return 0;
}
