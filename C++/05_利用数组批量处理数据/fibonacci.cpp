//f[i]=f[i-1]+f[i-2]
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
int f[20]={1,1},i;
for(i=2;i<=19;i++)f[i]=f[i-1]+f[i-2];
for (i=0;i<=19;i++)
	{
	if(i%5==0&&i!=0)cout<<endl;
	cout<<setw(8)<<f[i];
	}
return 0;
}
