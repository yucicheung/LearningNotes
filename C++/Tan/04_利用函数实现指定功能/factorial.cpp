#include<iostream>
using namespace std;
long int fact(int n)
{
if (n==1) return 1;
else return n*fact(n-1);
}
int main()
{
long int num;
while (true)
	{
	cout<<"Input num:";
	cin>>num;
	if(num>=1)cout<<num<<"!="<<fact(num)<<endl;
	else continue;
	}
return 0;
}
