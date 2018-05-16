//virtual base class makes sure that members from the shared base class only show up once
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string nam,char s,int a):name(nam),sex(s),age(a){};
protected:
	string name;
	char sex;
	int age;
};

class Teacher:virtual public Person
{
public:
	Teacher(string nam,char s,int a,string t):Person(nam,s,a),title(t){};
protected:
	string title;
};

class Student:virtual public Person
{
public:
	Student(string nam,char s,int a,float score):Person(nam,s,a),score(score){};
protected:
	float score;
};

class Graduate:public Teacher,public Student
{
public:
	Graduate(string nam,char s,int a,string t,float score,float w):Person(nam,s,a),Teacher(nam,s,a,t),Student(nam,s,a,score),wage(w){};
	void show();
private:
	float wage;
};
void Graduate::show()
{
cout<<"name:"<<name<<endl;
cout<<"age:"<<age<<endl;
cout<<"sex:"<<sex<<endl;
cout<<"title:"<<title<<endl;
cout<<"score:"<<score<<endl;
cout<<"wage:"<<wage<<endl;
}

int main()
{
Graduate grad("Zhang",'f',23,"assistant",99.9,1000);
grad.show();
return 0;
}
