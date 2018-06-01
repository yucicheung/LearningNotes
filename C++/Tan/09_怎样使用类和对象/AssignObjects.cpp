#include<iostream>
using namespace std;
class Box
{
public:
	Box(int h=10,int w=10,int l=10):height(h),width(w),length(l){};
	void volume();
private:
	int height;
	int width;
	int length;
};
void Box::volume()
{cout<<height*width*length<<endl;}

int main()
{
Box box1,box2(2,3,4);
box1.volume();
cout<<endl;
box2.volume();
box2=box1;
box2.volume();
return 0;
}
