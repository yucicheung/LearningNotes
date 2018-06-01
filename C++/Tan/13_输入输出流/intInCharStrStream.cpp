#include<iostream>
#include<strstream>

using namespace std;

int main()
{
char c[50]="12 34 65 -23 -32 33 61 99 321 32";
int a[10];
cout<<"array c:"<<c<<endl;

istrstream stri(c,sizeof(c));//input to memory from char array
//stri<<c;//comment this line will lead to the corrextness of running this sentence
for (int i=0;i<=9;i++)stri>>a[i];//input to memory
for (int i=0;i<=9;i++)cout<<a[i]<<endl;
void bubbleSort(int[],int len);
bubbleSort(a,10);

ostrstream stro(c,sizeof(c),ios::out);//output from memory to char array.
for(int i=0;i<=9;i++)stro<<a[i]<<' ',cout<<a[i]<<endl;//output to char array
stro<<ends;//碰到换行符则输出到字符数组
cout<<"new array c:"<<c<<endl;
return 0;
}

void bubbleSort(int a[],int len)
{
int temp;
for(int i=0;i<len;i++)//range control
	for(int j=0;j<len-i;j++)
		(a[j]<=a[j+1])?:(temp=a[j],a[j]=a[j+1],a[j+1]=temp);
//for(int i=0;i<len;i++)
//	cout<<a[i]<<endl;
}
