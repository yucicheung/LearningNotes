#include<iostream>
using namespace std;

float add(float f1,float f2){return (f1+f2);}
int main()
{
float f1,f2;
cout<<"Input 2 decimal numbers:";
cin>>f1>>f2;
cout<<"Sum of 2 numbers:"<<add(f1,f2)<<endl;
return 0;
}
