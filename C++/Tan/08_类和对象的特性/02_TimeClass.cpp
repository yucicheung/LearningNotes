#include <iostream>
using namespace std;
class Time
{
public:
	int hour;
	int minute;
	int sec;
};

int main()
{
void setTime(Time& t);
void showTime(Time& t);
Time t;
setTime(t);
showTime(t);
return 0;
}

void setTime(Time& t)
{
t.hour=10;
t.minute=33;
t.sec=36;
}

void showTime(Time& t)
{
cout<<t.hour<<':'<<t.minute<<':'<<t.sec<<endl;
}
