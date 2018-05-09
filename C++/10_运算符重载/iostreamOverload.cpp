#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(){real=0,imag=0;};
	Complex(int r,int i):real(r),imag(i){};
	//void display();
	Complex operator+(Complex&);
	friend ostream& operator<<(ostream&,Complex&);
	friend istream& operator>>(istream&,Complex&);
private:
	int real;
	int imag;
};
/*
void Complex::display()
{
cout<<real<<'+'<<imag<<'i'<<endl;
}
*/
Complex Complex::operator+(Complex& a) 
{
return (Complex(a.real+real,a.imag+imag));
}

ostream& operator<<(ostream& output,Complex& c)//call function
{
if (c.imag>0) output<<'('<<c.real<<'+'<<c.imag<<'i'<<')'<<endl;
if (c.imag==0) output<<'('<<c.real<<')'<<endl;
if (c.imag<0) output<<'('<<c.real<<c.imag<<'i'<<')'<<endl;
return output;
}

istream& operator>>(istream& input,Complex& c)
{
cout<<"Input real part and imaginary part of complex numbers:"<<endl;
input>>c.real>>c.imag;
return input;
}

int main()
{
Complex a(-1,5),b(-7,9),c,d;
c=a+b;
cout<<"c="<<c;
cin>>c>>d;
cout<<"c="<<c<<"d="<<d;
return 0;
}
