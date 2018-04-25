#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	int f(int x,int y,int z);
	cin>>a>>b>>c;
	cout<<f(a,b,c);
	return 0;
}

int f(int x,int y, int z)
{
	int min;
	if(x<y) min=x;else min=y;
	if(min>z) min=z;
	return min;
}
