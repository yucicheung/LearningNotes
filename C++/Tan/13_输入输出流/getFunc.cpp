#include<iostream>
using namespace std;

int main()
{
char c;
cout<<"enter a sentence:"<<endl;
//get char from console and assign it to variable
while((c=cin.get())!=EOF) cout.put(c);
//get char from console through func call
/*
cin.get(c);
cout<<c;
char input[10];
cin.get(input,10,EOF);
cout<<input;
*/
return 0;
}
