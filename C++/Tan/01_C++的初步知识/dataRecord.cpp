#include <iostream>
using namespace std;

class Student
{
	private:
		int num;
		int score;
	public:
		void setdata()
		{
			cin>>num>>score;
		}
		void readdata()
		{
			cout<<"num="<<num<<endl;
			cout<<"score="<<score<<endl;
		};
};
Student stu1,stu2;

int main()
{
	stu1.setdata();
	stu2.setdata();
	stu1.readdata();
	stu2.readdata();
	return 0;
}
