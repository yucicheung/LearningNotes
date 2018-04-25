#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	char c;
	//int e='e';
	//cout<<e;
	putchar(getchar()-32),putchar('\n');
	cout<<getchar(),cout<<(c=getchar()-32);
	return 0;
}
