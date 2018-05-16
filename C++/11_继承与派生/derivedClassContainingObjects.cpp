#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(int n, string nam):name(nam),num(n){};
	void display()
	{cout<<"num:"<<num<<endl<<"name:"<<name<<endl;}
protected:
	int num;
	string name;
};

//son constructor containing an object
class Student1: public Student
{
public:
	Student1(int n,string nam,int n1,string nam1,int a,string ad):
		Student(n,nam),addr(ad),age(a),monitor(n1,nam1){};
	void show()
	{
	cout<<"Student:"<<endl;
	display();
	cout<<"age:"<<age<<endl;
	cout<<"address:"<<addr<<endl;
	}

	void show_monitor()
	{cout<<endl<<"Monitor:"<<endl;monitor.display();}

private:
	Student monitor;
	int age;
	string addr;
};

int main()
{
Student1 stu1(10010,"Wang Li",10001,"Li Sun",19,"115 Beijing Road,Shanghai");
stu1.show();
stu1.show_monitor();
return 0;
}
