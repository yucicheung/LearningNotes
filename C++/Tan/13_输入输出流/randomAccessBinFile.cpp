#include<fstream>
#include<iostream>
using namespace std;
struct Student
{
int num;
string name;
float score;
};

int main()
{
Student stu[5]={1001,"Li",85,1002,"Fang",97.5,1004,"Wang",54,1006,"Tan",76.5,1010,"Ling",96};
string filename="stu.dat";

//write stu[] to bin file
fstream binfile(filename,fstream::binary|fstream::in|fstream::out);
if(!binfile)
	{
	cerr<<"open "<<filename<<" error!"<<endl;
	exit(1);
	}
binfile.write((char*)(&stu[0]),sizeof(stu));

//binfile.close()// we do not close file here for we
void displayStuOnScreen(Student[],int length);
displayStuOnScreen(stu,5);

Student stu1[3];
int len=sizeof(stu1[0]);
for(int i=0;i<=2;i++)
	{
	binfile.seekg(2*i*len,fstream::beg);//fstream::beg is same as ios::stream
	binfile.read((char*)(&stu1[i]),len);
	}
//displayStuOnScreen(stu1,3);

stu1[2].num=1012;
stu1[2].name="Wu";
stu1[2].score=60;
displayStuOnScreen(stu1,3);
for(int i=0;i<=2;i++)//use stud1[](memory) to change contents in bin file,write
	{
	binfile.seekp(len*2*i,ios::beg);
	binfile.write((char*)(&stu1[i]),len);
	}

binfile.seekg(0,ios::beg);
for(int i=0;i<=4;i++)
	{
	binfile.read((char*)(&stu[i]),len);
	}
displayStuOnScreen(stu,5);

binfile.close();//always remember to close file
return 0;
}

void displayStuOnScreen(Student stu[],int len)//Student* stu
{
for(int i=0;i<len;i++)
	{
	cout<<"Index="<<i<<endl;
	cout<<"num="<<stu[i].num<<" name="<<stu[i].name<<" score="<<stu[i].score<<endl;
	}
}
