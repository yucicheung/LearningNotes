#include<iostream>
#include<string>
using namespace std;

//abstract class
class Shape
{
public:
	//constructor is not necessary
	virtual float area() {return 0.0;}//virtual function
	virtual float volume() {return 0.0;}//virtual function
	virtual void shapeName() =0;// pure virtual function
};

//concrete class
class Point:public Shape
{
public:
	Point(float a=0,float b=0):x(a),y(b){};
	void setPoint(float a,float b){x=a,y=b;}
	float getX() const {return x;} 
	float getY() const {return y;}
	virtual void shapeName() {cout<<"This is a point!"<<endl;}
	friend ostream& operator<<(ostream&, Point&);
protected:
	float x,y;
};

ostream& operator<<(ostream& output, Point& p)
{
output<<"["<<p.x<<","<<p.y<<"]"<<endl;
return output;
}

class Circle:public Point
{
public:
	Circle(float x=0,float y=0,float r=0):Point(x,y),radius(r){};
	void setRadius(float r){radius=r;}
	float getRadius() const {return radius;}
	virtual float area(){return (3.141592653*radius*radius);}
	virtual void shapeName(){cout<<"This is a circle!"<<endl;}
	friend ostream& operator<<(ostream&,const Circle &);
protected:
	float radius;
};
ostream& operator<<(ostream& output,const Circle& c)
{
output<<"Center at ["<<c.x<<','<<c.y<<"], radius is "<<c.radius<<endl;
return output;
}

class Cylinder:public Circle
{
public:
	Cylinder(float x=0,float y=0,float r=0, float h=0):Circle(x,y,r),height(h){};
	void setHeight(float h){height=h;}
	float getHeight(){return height;}
	virtual float area(){return (2*3.1415926*radius*height+Circle::area()*2);}
	virtual float volume(){return (Circle::area()*height);}
	virtual void shapeName(){cout<<"This is a cylinder!"<<endl;}
	friend ostream& operator<<(ostream&,Cylinder&);
private:
	float height;
};
ostream& operator<<(ostream& output,Cylinder& c)
{
output<<"center:["<<c.x<<','<<c.y<<"],radius "<<c.radius<<",height "<<c.height<<endl;
return output;
}

int main()
{
//test point
Point point(3.2,4.5);
point.shapeName();
cout<<point;

//test circle
Circle circle(2.4,1.2,5.6);
circle.shapeName();
cout<<circle;

//test cylinder
Cylinder cylinder(3.5,6.4,5.2,10.5);
cylinder.shapeName();
cout<<cylinder;

//polymorphism
Shape* pt;
pt = &point;
pt->shapeName();
cout<<"Point area "<<pt->area()<<",volume "<<pt->volume()<<endl;

pt = &circle;
pt->shapeName();
cout<<"Circle area "<<pt->area()<<",volume "<<pt->volume()<<endl;

pt = & cylinder;
pt->shapeName();
cout<<"Cylinder area "<<pt->area()<<",volume "<<pt->volume()<<endl;

return 0;
}
