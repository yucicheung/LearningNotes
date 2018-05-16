//test the derivated func is able to assign derivated object to base object
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(int n,string nam,float s):score(s),name(nam),num(n){};
	void display();
private:
	int num;
	string name;
	float score;
};
void Student::display()
{
cout<<endl<<"num:"<<num<<endl;
cout<<"name:"<<name<<endl;
cout<<"score"<<score<<endl;
}

class Graduate:public Student
{
public:
	Graduate(int n,string nam,float s,float w):Student(n,nam,s),wage(w){};
	void display();//override
private:
	float wage;
};
void Graduate::display()
{
Student::display();
cout<<"wage:"<<wage<<endl;
}

int main()
{
Graduate grad(10001,"Zhang",99.9,10000);
//About compatibility
Student& stu=grad;//assign to reference
Student* p=&grad;//assign pointer
grad.display();
stu.display();//base class dispaly
p->display();//base class pointer display
return 0;
}
