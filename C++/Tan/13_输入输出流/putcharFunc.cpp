//putchar() is defined in head file "iostream"
#include<iostream>
using namespace std;

int main()
{
char *p="BASIC";
for (int i=4;i>=0;i--) putchar(*(p+i));
putchar('\n');
return 0;
}
