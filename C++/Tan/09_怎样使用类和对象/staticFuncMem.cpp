#include<iomanip>
#include<iostream>
using namespace std;
class Student
{
public:
	Student(int n,int a,int s):num(n),age(a),score(s){};
	void total();
	static float average();
private:
	int num;
	int age;
	int score;
	static float sum;
	static int count;
};

void Student::total()
{
sum += score;//this->score
count++;
}

float Student::average()
{
return sum/count;//refer to static members only
}

float Student::sum=0;
int Student::count=0;

int main()
{
Student stus[3]={
	Student(1001,18,70),
	Student(1002,19,78),
	Student(1005,20,98)};
int i;
for (i=0;i<=2;i++) stus[i].total();
cout<<setiosflags(ios::fixed)<<setprecision(3)<<Student::average()<<endl;// call by class name
cout<<stus[1].average()<<endl;// call by object name
return 0;
}
