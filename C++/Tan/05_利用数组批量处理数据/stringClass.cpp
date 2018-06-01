#include<iostream>
#include<string>
using namespace std;

int main()
{
string str1="china",str2="hello";
cout<<str1<<endl;
cout<<(str1[4]='e',str1)<<endl;
cout<<(str1=str2)<<endl;
cout<<sizeof(string)<<endl;
cout<<sizeof(str1)<<endl;
return 0;
}
