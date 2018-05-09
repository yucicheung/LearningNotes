#include <iostream>
using namespace std;
class Time
{
public:
	void setTime(int h,int m,int s);
	void showTime();	
private:
	int hour;
	int minute;
	int sec;
};

void Time::setTime(int h=0,int m=0,int s=0)
{
hour = h;
minute = m;
sec = s;
}

void Time::showTime()
{
cout<<hour<<':'<<minute<<':'<<sec<<endl;
}

int main()
{
Time t;
t.setTime(10,36,45);
t.showTime();
t.setTime();
t.showTime();
return 0;
}
