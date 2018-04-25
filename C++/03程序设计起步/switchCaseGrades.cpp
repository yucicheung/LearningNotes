#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
char grades;
cout<<"Input grades class:";
cin>>grades;
switch(grades)
	{
	default: cout<<"Error!"<<endl;
	case 'A': cout<<"85-100\n";break;
	case 'B': cout<<"70-84"<<endl;break;
	case 'C': cout<<"60-69"<<endl;break;
	case 'D': cout<<"<60"<<endl;break;
	}
return 0;
}
