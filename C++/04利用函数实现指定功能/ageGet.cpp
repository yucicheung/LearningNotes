#include<iostream>
using namespace std;
int age(int num)
{
if (num==1)return 10;
else return age(num-1)+2;
}
int main()
{int num=5;
cout<<age(5)<<endl;
return 0;
}
