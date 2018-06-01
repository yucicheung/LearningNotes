#include<iostream>
using namespace std;
int fibo(int n)
{
int ans;
if(n>2) ans=fibo(n-1)+fibo(n-2);
else ans=1;
return ans;
}

int main()
{
int i;
for(;i<=40;i++)cout<<fibo(i)<<endl;
return 0;
}
