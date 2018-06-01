//input should be "Li 1001","Zhang 1002","Wang 1003","Tan 1004","Sun 1005"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
string name[50],num[50];
int length;

void inputData(int len)
{int i;
for(i=0;i<=len-1;i++)
	{cout<<"Input the name and number of student:";
	cin>>name[i]>>num[i];}
}

void search(string str)
{
int i=0;
for(i;i<=length-1;i++)
	{
	if(str==name[i])
		{
		cout<<setw(8)<<name[i]<<setw(8)<<num[i]<<endl;
		//return;//return void
		return void();
		}
	}
cout<<"No such record"<<endl;
}

int main()
{
string targetName;
int i;
cout<<"Input the num of records you want to input:"<<endl;
cin>>length;
inputData(length);
while (true)
	{
	cout<<"Input the name you want to search:";
	cin>>targetName;
	search(targetName);
	}
return 0;
}
