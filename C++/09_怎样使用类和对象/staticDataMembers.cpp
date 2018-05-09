#include<iostream>
using namespace std;
class Box
{
public:
	Box(int h, int l=10):height(h),length(l){};
	int volume();
	static int width;
private:
	int length;
	int height;
};
int Box::width=10;
int Box::volume()
{
//Box::width=10;
//width=33;
return (width*height*length);
}

int main()
{
Box box1(10,10);
box1.width=30;
cout<<box1.volume()<<endl;
cout<<(Box::width=40,box1.volume())<<endl;
return 0;
}
