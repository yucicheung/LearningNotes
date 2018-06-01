//samllest to largest
#include<iostream>
using namespace std;

int main()
{
int a[10]={3,5,9,11,33,6,-9,-76,100,123},i,j,temp;
for (j=8;j>=0;j--)
	{	
	for (i=0;i<=j;i++)(a[i]<a[i+1])?:(temp=a[i],a[i]=a[i+1],a[i+1]=temp);//:temp;
	cout<<a[j+1]<<endl;
	}
cout<<a[0]<<endl;
return 0;
}
