#include<iostream>
using namespace std;
class Time
{
public:
	Time(int h,int m,int s):hour(h),minute(m),second(s){};
	friend void display(Time&);//system will find it is a regular func
private:
	int hour;
	int minute;
	int second;
};

void display(Time& t)
{
//friend func is allowed to visit private members
cout<<"Time is "<<t.hour<<':'<<t.minute<<':'<<t.second<<endl;
}

int main()
{
Time t1(10,10,10);
display(t1);
return 0;
}
