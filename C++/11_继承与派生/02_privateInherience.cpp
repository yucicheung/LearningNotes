#include<iostream>
using namespace std;
class Student
{
public:
	void getValue()
		{
		cout<<"input num:";cin>>num;
		cout<<"input name:";cin>>name;
		cout<<"input sex:";cin>>sex;
		}
	void display()
		{cout<<"num:"<<num<<endl;cout<<"name:"<<name<<endl;cout<<"sex:"<<sex<<endl;}
private:
	int num;
	string name;
	char sex;
};

class Student1: private Student
{
public:
	
	void getValue1()
		{
		getValue();
		cout<<"input age:";cin>>age;
		cout<<"input address:";cin>>addr;
		}
	
	void display1()
		{
		display();
		cout<<"age:"<<age<<endl;
		cout<<"address:"<<addr<<endl;
		}
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
