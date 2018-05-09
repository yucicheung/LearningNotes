#include<iostream>
using namespace std;
class Date;
class Time
{
public:
	Time(int h,int m,int s):hour(h),second(s),minute(m){};
	void display(Date&);
private:
	int hour;
	int second;
	int minute;
};

class Date
{
public:
	Date(int m,int d,int y):month(m),day(d),year(y){};
	friend void Time::display(Date&);
private:
	//int month;
	//int day;
	//int year;
	int month,year,day;
};

void Time::display(Date& d)
{
cout<<d.month<<'/'<<d.day<<'/'<<d.year<<endl;
cout<<hour<<':'<<minute<<':'<<second<<endl;
}

int main()
{
Time t(10,10,10);
Date d(5,5,2018);
t.display(d);
return 0;
}
