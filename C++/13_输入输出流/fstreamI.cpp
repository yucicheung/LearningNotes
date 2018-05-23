#include<fstream>
#include<iostream>
using namespace std;

int main()
{
int a[10];
fstream file("f1.dat",ios::in);
if(!file)
	{
	cerr<<"open error!"<<endl;
	exit(1);
	}
for(int i=0;i<=9;i++)
	{
	file>>a[i];
	}
file.close();//always remember to close files
void maxOfArray(int[],int);
maxOfArray(a,9);
return 0;
}

void maxOfArray(int a[],int len)
{
int max=a[0],index=0;
for(int i=1;i<=len;i++)
	{
	max>a[i]?:(max=a[i],index=i);
	}
cout<<"Max is "<<max<<",index="<<index<<endl;
}
