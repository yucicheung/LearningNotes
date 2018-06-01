//Vitual function is used for functions sharing the same name in different levels of inheritance
//When pointer points to different class(base class or derivated class)
//the virtual function is able to visit all the members of that class instead of that of only base class
#include<iostream>
using namespace std;
class Student
{
public:
	Student(int n,string nam,float s):num(n),name(nam),score(s){};
	//virtual func makes display func to work in different class
	virtual void display();
	//normal func only calls what exists in base class
	//void display();
protected:
	int num;
	string name;
	float score;
};
void Student::display()
{
cout<<"num:"<<num<<"\nname:"<<name<<"\nscore:"<<score<<"\n";
}

class Graduate:public Student
{
public:
	Graduate(int n,string nam,float s,float w):Student(n,nam,s),wage(w){};
	void display();
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
Student stu(1001,"Zhang",99.9);
Graduate grad(2001,"Wang",98.5,1200);
Student *p = &stu;
p->display();
p = & grad;
p->display();
return 0;
}
