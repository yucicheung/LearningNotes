#include<iostream>
#include<string>
using namespace std;
class Teacher
{public:
	Teacher(string n,int a,string t):name(n),age(a),title(t){};
	void display();
protected:
	string name;
	int age;
	string title;
};
void Teacher::display()
{
cout<<"name:"<<name<<endl;
cout<<"age:"<<age<<endl;
cout<<"title:"<<title<<endl;
}
//In multi inheritance
//members from different base class are allowed to have same names
//members sharing name does not cause ambiguity if it only shows up in base class
//however if you want to call member in derivated func,you should specify the scope to avoid ambiguity
class Student
{
public:
	Student(string n,string gen,float s):name(n),gender(gen),score(s){};
	void display();
protected:
	string name;
	string gender;
	float score;
};
void Student::display()
{
cout<<"name:"<<name<<endl;
cout<<"gender:"<<gender<<endl;
cout<<"score:"<<score<<endl;
}

class Graduate:public Teacher,public Student//multi inheritance
{
public:
	Graduate(string name,int age,string title,string gender,float score)
	:Teacher(name,age,title),Student(name,gender,score){};
	void show();
private:
	float wage;
};
void Graduate::show()
{
Teacher::display();
Student::display();
cout<<"wage:"<<wage<<endl;
}

int main()
{
Graduate grad("Zhang",23,"assistant","female",99.99);
grad.show();
return 0;
}
