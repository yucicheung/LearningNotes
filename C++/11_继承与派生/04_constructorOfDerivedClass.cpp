#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(int n,string nam,char s):num(n),name(nam),sex(s){};	
protected:
	int num;
	string name;
	char sex;
};

class Student1:public Student
{
public:
	// all are r
	//Student1(int n,string nam,char s,int ag,string ad):Student(n,nam,s),age(ag),addr(ad){};
	//Student1(int n,string nam,char s,int ag,string ad):age(ag),addr(ad),Student(n,nam,s){};
	
	Student1(int n,string nam,char s,int ag,string ad):Student(n,nam,s)
	{age=ag,addr=ad;}
	
	void show();
	~Student1(){};
private:
	int age;
	string addr;
};

void Student1::show()
{
cout<<"num:"<<num<<endl;
cout<<"name:"<<name<<endl;
cout<<"sex:"<<sex<<endl;
cout<<"age:"<<age<<endl;
cout<<"address:"<<addr<<endl;
}

int main()
{
Student1 stu(12,"Zhang",'f',23,"Xi'an");
stu.show();
return 0;
}
