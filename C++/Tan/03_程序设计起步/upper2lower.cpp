#include<iostream>
using namespace std;
int main()
{
char ch;
cout<<"Please input a letter:";
cin>>ch;
cout<<((ch>'A'&&ch<'Z')?ch:(ch-=32))<<endl;
return 0;
}
