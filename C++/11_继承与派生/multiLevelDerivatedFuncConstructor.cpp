#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(int n,string nam):name(nam),num(n){};
	void display()
	{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	}
protected:
	int num;
	string name;
};

class Student1:public Student
{
public:
	Student1(int n,string nam,int a):Student(n,nam),age(a){};
	void show()
		{display();cout<<"age:"<<age<<endl;}
private:
	int age;
};

class Student2:public Student1
{
public:
	Student2(int n,string nam,int a,int s):Student1(n,nam,a),score(s){};
	void display()// func name is allowed to be same with that of indirecitve function
		{
		show();
		cout<<"Score:"<<score<<endl;
		}
private:
	int score;
};

int main()
{
Student2 stu(10001,"Zhang",23,100);
stu.display();
return 0;
}
