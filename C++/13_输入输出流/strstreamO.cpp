#include<strstream>
#include<iostream>
using namespace std;

struct Student
{
int num;
char name[20];
float score;
};

int main()
{
Student stu[3]={1001,"Li",78,1002,"Wang",89.5,1004,"Fang",90};
char cbuffer[50];
ostrstream strout(cbuffer,30);//char buffer in memory,smaller length leads to truncating the string
for(int i=0;i<3;i++)
	strout<<stu[i].num<<stu[i].name<<stu[i].score;
//strout<<ends;//ie`\0`,this is necessary for cout to know where to end the string
//after all elements in stu[] are transferred to cbuffer
//output to screen
cout<<cbuffer;
return 0;
}
