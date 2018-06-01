#include<iostream>
using namespace std;

int main()
{
char ch[20];
cin.getline(ch,20,'/');
cout<<"The first part:"<<ch<<endl;
cin.getline(ch,20,'/');
cout<<ch<<endl;
cout<<"The 2nd part is:"<<ch<<endl;
return 0;
}
