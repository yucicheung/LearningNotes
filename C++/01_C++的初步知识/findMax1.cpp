#include<iostream>
using namespace std;

int main()
{
	int x,y;
	int max(int x,int y);
	cout<<"Please input a and b:";
	cin>>x>>y;
	//cout<<"maximum is "<<max(x,y)<<endl;
	cout<<"maximum is "<<max(x,y)<<'\n';
}

int max(int x,int y)
{
	int max;
	if (x>y) max = x;
	else max = y;
	return max;
}

