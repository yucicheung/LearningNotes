#include<iostream>
using namespace std;
class Time
{
public:
	Time(){sec=0,minute=0;}
	Time(int m,int s):minute(m),sec(s){};
	void operator++();//prefix
	Time operator++(int);//postfix
	void display();
private:
	int minute;
	int sec;
};

void Time::operator++()//augment to ori then return
{
if(++sec>=60) {sec-=60,minute++;}
//return (*this);
}

Time Time::operator++(int)//save ori and aug this then return ori
{
Time tmp(*this);//save original value
sec++;
if(sec>=60) {sec-=60,minute++;}
return tmp;
}

void Time::display()
{
cout<<minute<<':'<<sec<<endl;
}

int main()
{
Time t(12,59),tmp;
t.display();
++t;
t.display();
tmp=t++;
tmp.display();
t.display();
return 0;
}
