//Like the opposite way of Bubble sort
//find  samllest as a[smallestIndex]
//smallest to largest
//use loop instead of recursion
#include <iostream>
#include<iomanip>
using namespace std;
void selectionSort(int a[],int len)
{
int i=0,temp,j;
len--;
for (i;i<=len-1;i++)for(j=i+1;j<=len;j++) a[i]<a[j]?:(temp=a[i],a[i]=a[j],a[j]=temp);
}

int main()
{
int a[10]={6,9,-2,56,87,11,-54,3,0,77};
int i,len=10;
selectionSort(a,len);
for(i=0;i<=9;i++)cout<<setw(3)<<a[i]<<endl;
return 0;
}
