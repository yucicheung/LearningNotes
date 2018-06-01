#include<iostream>
using namespace std;
void f()
{
auto int b=1;
static int c=1;
cout<<"b="<<b<<" c="<<c<<endl;
c++,b++;
}

int main()
{
int i;
for(i=0;i<=3;i++) f();
return 0;
}
