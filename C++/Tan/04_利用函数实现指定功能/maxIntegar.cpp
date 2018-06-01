#include<iostream>
using namespace std;
int max(int x,int y)
{
return (x>y)?x:y;
}
int main()
{
int int1,int2;
cout<<"Input 2 integars:";
cin>>int1>>int2;
cout<<"Max of 2 integars:"<<max(int1,int2)<<endl;
return 0;
}
