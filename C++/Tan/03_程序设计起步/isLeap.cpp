#include<iostream>
using namespace std;

int main()
{
int year;
bool leap=false;
cout<<"Input year:";
cin>>year;
if((year%4==0 && year%100)|| year%400==0) leap=true;
cout<<(leap?"True":"False")<<endl;
}
