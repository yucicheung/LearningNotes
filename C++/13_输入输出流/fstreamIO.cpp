#include<fstream>
#include<iostream>

using namespace std;

int main()
{
fstream file;
if(!file.open("f2.dat",ios::out))
	{cerr<<"open error!"<<endl;
	exit(1);}
char c[80];//coz we want to process characters one by one
cout<<"Please input chars:";
cin.getline();//read in one line instead of one by one
for(int i=0;;i++)
	{
	
	}
lower2upper
file.close();

file.open("f3.dat",ios::in);
file.
return 0;
}
