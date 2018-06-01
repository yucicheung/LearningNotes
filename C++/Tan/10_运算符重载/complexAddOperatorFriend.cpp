#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(){real=0,imag=0;}
	Complex(int r,int i):real(r),imag(i){};
	Complex(int r):real(r),imag(0){};
	void display();
	Complex operator + (Complex &);
	Complex operator + (int);
	friend Complex operator +(int ,Complex &);
private:
	int real;
	int imag;
};

void Complex::display()
{
cout<<real<<'+'<<imag<<'i'<<endl;
}

Complex Complex::operator +(Complex& a)
{
return(Complex(a.real+real,a.imag+imag));
}

Complex Complex::operator+(int i)
{
return (Complex(real+i,imag));
}


Complex operator+ (int x,Complex &a)
{
return (Complex(x+a.real,a.imag));
}

int main()
{
Complex a(2),b(3,4),c;
a.display();
c = a + b;
c.display();
c = c + 2;
c.display();
c = 2 + c;
c.display();
return 0;
}
