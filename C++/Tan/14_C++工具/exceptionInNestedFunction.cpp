//抛出的异常如果本层次处理不了就交由上层处理
//如果上层也处理不了，就继续交由上层处理
//一直到遇到匹配的catch块
#include<iostream>
using namespace std;

int main()
{
void f1();
try
	{f1();}
catch(int)
	{cout<<"ERROR0"<<endl;}
cout<<"end0"<<endl;
return 0;
}

void f1()
{
void f2();
double a = 0;
try
	{f2();}
catch(int)
	{cout<<"ERROR1"<<endl;
	throw;}
cout<<"end1"<<endl;
}

void f2()
{
void f3();
int i=0;
try
	{f3();}
catch(double)
	{cout<<"ERROR2"<<endl;
	throw i;}
cout<<"end2"<<endl;
}

void f3()
{
double a=0;
try
	{throw a;}//message thrown is of type double
catch(double)
	{cout<<"ERROR3"<<endl;
	throw;//tranfer to upper class
	}
cout<<"end3"<<endl;
}
