#include<iostream>
//#include<math>
using namespace std;

class Point
{
public:
	Point(float x=0,float y=0):x(x),y(y){};
	void setPoint(float a,float b){x=a,y=b;}
	//const for member func not able to modify data members
	float getX() const{return x;}
	float getY() const{return y;}
	friend ostream& operator<<(ostream&,Point&);
	friend istream& operator>>(istream&,Point&);
protected:
//private:
	float x;
	float y;
};
ostream& operator<<(ostream& output,Point& p)
{
output<<'['<<p.x<<','<<p.y<<']'<<endl;
return output;
}
istream& operator>>(istream& input,Point& p)
{
cout<<"Please input x and y:"<<endl;
input>>p.x>>p.y;
return input;
}

class Circle:public Point
{
public:
	Circle(float x=0,float y=0,float r=0):Point(x,y),r(r){};
	void setRadius(float radius){r=radius;}
	float getRadius() const{return r;}
	float area() const{return (r*r*3.1415);}
	friend istream& operator>>(istream&,Circle&);
	friend ostream& operator<<(ostream&,Circle&);
protected:
	float r;
};

istream& operator>>(istream& input,Circle& c)
{
cout<<"Input x y and radius:"<<endl;
input>>c.x>>c.y>>c.r;
return input; 
}

ostream& operator<<(ostream& output,Circle& c)
{
output<<"center:["<<c.x<<','<<c.y<<']'<<','<<"radius:"<<c.r<<endl;
return output;
}

class Cylinder:public Circle
{
public:
	Cylinder(float x=0,float y=0,float r=0,float h=0):Circle(x,y,r),h(h){};
	void setHeight(float height){h=height;}
	float getHeight(){return h;}
	float area(){return (2*Circle::area()+2*3.1415*r*h);}
	float volume(){return (Circle::area()*h);}
	friend istream& operator>>(istream&,Cylinder&);
	friend ostream& operator<<(ostream&,Cylinder&);
private:
	float h;
};

istream& operator>>(istream& input, Cylinder& c)
{cout<<"Input x,y r and h"<<endl;
input>>c.x>>c.y>>c.r>>c.h;
return input;
}
ostream& operator<<(ostream& output, Cylinder& c)
{
output<<"Center ["<<c.x<<','<<c.y<<"],radius"<<c.r<<",height"<<c.h<<endl;
return output;
}

int main()
{
/* Test Cylinder*/
Cylinder cylinder;
cout<<"Intial cylinder is "<<endl<<cylinder;
cylinder.setHeight(8);
cylinder.setRadius(10);
cout<<"New cylinder is "<<endl<<cylinder;
cout<<"Area is "<<cylinder.area()<<endl;
cout<<"Volume is "<<cylinder.volume()<<endl;

/*Test Point
Point point(1,1);
cout<<"Initial point is "<<point;
cin>>point;
cout<<"New point:"<<point;
point.setPoint(2,2);
cout<<"x:"<<point.getX()<<",y:"<<point.getY()<<endl;
*/
/* Test Circle
//Circle c(3,4,10);
Circle c;
cout<<"Initial circle is"<<c;
cin>>c;
cout<<"new circle:"<<c;
c.setRadius(5);
cout<<"new radius is "<<c.getRadius()<<endl;
cout<<"Its area is "<<c.area()<<endl;
*/
return 0;
}

