#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Student
{int num;
string name;
float score;
};
Student stu={12345,"Li Li",67.5};

int main()
{
void print(Student &);
print(stu);
return 0;
}

void print(Student &stu)
{
cout<<setw(8)<<stu.num<<setw(8)<<stu.name<<setw(8)<<stu.score<<endl;
}
