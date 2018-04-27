#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int b[3][2],a[2][3]={1,2,3,4,5,6},i,j;
for (i=0;i<=1;i++) for(j=0;j<=2;j++) b[j][i]=a[i][j];
for(i=0;i<=2;i++)
	{
	for(j=0;j<=1;j++)cout<<setw(8)<<b[i][j];
	cout<<endl;
	}
return 0;
}
