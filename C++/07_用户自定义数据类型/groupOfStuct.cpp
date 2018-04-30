#include<iostream>
#include<string>
using namespace std;
struct Person
{
string name;
int count;
};

int main()
{
//Person leaders[3]={{"Li",0},{"Zhang",0},{"Sun",0}};
Person leaders[3];
leaders[0]={"Li",0};
leaders[1]={"Zhang",0};
leaders[2]={"Sun",0};
string vote[10]={"Zhang","Li","Sun","Li","Zhang","Li","Zhang","Li","Sun","Wang"};
int i,j;
for(i=0;i<=9;i++)
	for(j=0;j<=2;j++)
		if (*(vote+i)==(leaders+j)->name)
			{(leaders+j)->count++;break;}
for (i=0;i<=2;i++)
	cout<<(*(leaders+i)).count<<endl;
return 0;
}
