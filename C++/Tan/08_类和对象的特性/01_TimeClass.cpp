//data as public
//operate via statements in main function
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
Time t1;
t1.hour=10,t1.minute=16,t1.sec=59;
cout<<t1.hour<<':'<<t1.minute<<':'<<t1.sec<<endl;
return 0;
}
