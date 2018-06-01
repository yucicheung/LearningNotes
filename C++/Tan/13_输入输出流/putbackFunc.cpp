#include<iostream>

using namespace std;

int main()
{
char c[20];
int ch;
cout<<"please enter a sentence:"<<endl;
cin.getline(c,15,'/');//"I am a girl."从输入流中判断碰到'/'即截止为一句
cout<<"The first part is:"<<c<<endl;
cin.putback(c[10]);
cin.getline(c,15,'/');
cout<<"The second part is:"<<c;
return 0;
}
