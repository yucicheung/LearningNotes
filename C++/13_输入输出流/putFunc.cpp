#include<iostream>
#include<cstring>
using namespace std;

int main()
{
char *p ="BASIC";
for (int i=4;i>=0;i--) cout.put(*(p+i));
cout.put('\n');
return 0;
}
