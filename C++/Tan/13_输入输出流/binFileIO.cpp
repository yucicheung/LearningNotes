/*
 I got an segmentation fault unsolved for `Invalid Memory Reference`
*/

//In bin file, we use func member `read` and `write` to complish corresponding behaviors
//istream& read(char *buffer,int len);
//ostream& write(const char* buffer,int len);
//close()用于关闭流对象和文件之间的关联
//read和write自动实现ASCII和bin之间的转化
#include<fstream>
#include<iostream>
using namespace std;
struct Student
{
string name;
int num;
int age;
char sex;
};

int main()
{
string filename="dataBin.dat";
fstream binfile(filename,ios::binary|ios::out);
//fstream binfile(filename,ios::binary|ios::out);
if (!binfile)
	{
	cerr<<"open "<<filename<<" error!"<<endl;
	exit(1);
	//abort();
	}

//write to bin file
Student stu[3]={"Li",1001,18,'f',"Fang",1002,19,'m',"Wang",1004,17,'f'};
void displayStu(const Student[],int length);
displayStu(stu,3);
int len=sizeof(stu[0]);
/*write to file one at a time
for(int i=0;i<=2;i++)
	{
	//each time one data gets input, file pointer will be towards the end of file more.
	//cout<<sizeof(stu[i])<<endl;//48 for all
	binfile.write((char*)(&stu[i]),len);
	}
*/
cout<<sizeof(stu)<<endl;//48*3=144

/* write to file in one-time operation*/
binfile.write((char*)(&stu[0]),sizeof(stu));
binfile.close();//close the connection between file and fstream

// read from bin file
Student stuNew[3];
binfile.open(filename,ios::binary|ios::in);
if(!binfile.is_open())
	{
	cerr<<"open error!"<<endl;
	exit(1);
	}
/*read from file one at a time
for(int i=0;i<=2;i++)
	{
	binfile.read((char*)(&stuNew[i]),len);
	}
*/

/* read from file in one-time operation*/
binfile.read((char*)(&stuNew[0]),sizeof(stuNew));
displayStu(stuNew,3);
binfile.close();

return 0;
}

void displayStu(const Student stu[],int length)
{
for(int i=0;i<length;i++)
	{
	cout<<"name:"<<stu[i].name<<" num:"<<stu[i].num<<" age:"<<stu[i].age<<" sex:"<<stu[i].sex<<endl;
	}
}
