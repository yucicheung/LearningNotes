//select numbers from smallest to largest
#include<iostream>
#include<iomanip>
using namespace std;
void swap(int*p1, int*p2)
{
int tmp;
tmp=*p1;
*p1=*p2;
*p2=tmp;
}
void selectSort(int *a,int len)
{
int i,j;
cout<<sizeof(a)<<endl;
for(i=0;i<=len-2;i++)
	for(j=i+1;j<=len-1;j++)
		if(*(a+i)>*(a+j)) swap(a+i,a+j);
}

int main()
{
int a[10]={-34,78,0,2,3,11,4,22,67,18};
selectSort(a,10);
int i;
cout<<sizeof(a)<<endl;
for(i=0;i<=9;i++)cout<<setw(8)<<a[i];
cout<<endl;
return 0;
}
