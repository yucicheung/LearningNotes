#include<iostream>
using namespace std;
class Student//as base class thus contains protected members only
{
public:

protected:
	int num;
	string name;
	char sex;
};

class Student1:protected Student//as derived class
{
public:
	void getValue();
	void display();
private:
	int age;
	string addr;
};

void Student1::getValue()
{
cout<<"num:";cin>>num;
cout<<"name:";cin>>name;
cout<<"sex:";cin>>sex;
cout<<"addr:";cin>>addr;
}

void Student1::display()
{
cout<<"num:"<<num<<endl;
cout<<"name:"<<name<<endl;
cout<<"sex:"<<sex<<endl;
cout<<"age:"<<age<<endl;
cout<<"addr:"<<addr<<endl;
}

int main()
{
Student1 stu;
stu.getValue();
stu.display();
return 0;
}
