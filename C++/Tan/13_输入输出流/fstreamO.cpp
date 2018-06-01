#include<fstream>
#include<iostream>
using namespace std;

int main()
{
int a[10];
/*
fstream outfile("f1.dat",ios::out);
*/
ofstream outfile("f1.dat");//,ios::in);//ofstream只能用于输出，如果用于输入则报错

if(!outfile)
	{
	cerr<<"open error!"<<endl;
	exit(1);//异常退出
	}
cout<<"enter 10 integars:";
for(int i=0;i<=9;i++)
	{
	cin>>a[i];
	outfile<<a[i]<<endl;
	}
outfile.close();
return 0;
}
