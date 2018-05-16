#include<iostream>
using namespace std;
class Student
{
public:
	void getValue()
		{cout<<"Input num, name, sex:"<<endl;cin>>num>>name>>sex;}
	void display()
		{cout<<"num="<<num<<endl;cout<<"name="<<name<<endl;cout<<"sex="<<sex<<endl;}
private:
	int num;
	string name;
	char sex;
};

class Student1:public Student
{
public:
	void getValue1()
		{getValue();cout<<"Input age and address:"<<endl;cin>>age>>addr;}
	void display1()
		{display();cout<<"address="<<addr<<endl;cout<<"age="<<age<<endl;}
private:
	int age;
	string addr;
};

int main()
{
Student1 stu;
stu.getValue1();
stu.display1();
return 0;
}
