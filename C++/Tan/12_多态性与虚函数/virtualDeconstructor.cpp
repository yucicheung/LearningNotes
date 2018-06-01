#include<iostream>
#include<string>

using namespace std;

class Point
{
public:
	Point(){};
	virtual ~Point(){cout<<"executing Point Deconstructor."<<endl;}	
};

class Circle:public Point
{
public:
	Circle(){};
	~Circle(){cout<<"executing Circle Deconstructor."<<endl;};
};

int main()
{
/* case1:
when non-virtual deconstructor defined
delete an object only calls deconstructor from base class
here showed as "executing Point Deconstructor."
*/
Point *p= new Circle;
delete p;
return 0;
}
