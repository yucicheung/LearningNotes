#include<iostream>
#include<string>

using namespace std;

class Student
{
public:
	Student(int n,string nam):name(nam),num(n){cout<<"Constructor"<<num<<endl;}
	~Student(){cout<<"deconstructor~"<<num<<endl;}
	void getData();
private:
	int num;
	string name;
};

void Student::getData()
{
if(num==0)throw num;
else cout<<num<<" "<<name<<endl;
cout<<"in getData()"<<endl;
}

void fun()
{
Student stu1(1101,"Tan");
stu1.getData();
Student stu2(0,"Li");
stu2.getData();
}

int main()
{
try
	{fun();}
catch(int num)
	{
	cout<<"num="<<num<<",error!"<<endl;
	}
return 0;
}

