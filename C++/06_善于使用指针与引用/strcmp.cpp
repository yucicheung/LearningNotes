#include<iostream>
using namespace std;

int main()
{
char str1[]="I Love China!",str2[20];
int i=0;
while(*(str1+i)!='\0') *(str2+i)=*(str1+i),i++;
*(str2+i)='\0';
cout<<str2<<endl;
return 0;
}
