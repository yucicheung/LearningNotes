#include<iostream>
#include<string>
using namespace std;
struct Student
{
int num;
char sex;
string name;
};

int main()
{
Student *p;
p = new Student;
p->num=100;
p->sex='f';
p->name="Yuci";
cout<<p->num<<endl;
delete p;
return 0;
}
