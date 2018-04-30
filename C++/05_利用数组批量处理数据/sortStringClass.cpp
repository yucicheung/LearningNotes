//sort strings
#include<iostream>
#include<string>
using namespace std;
void sortStr(string str[])
{
string temp;
int i,j;
for (j=1;j>=0;j--) for (i=0;i<=j;i++) (str[i]<str[i+1])?str[i]:(temp=str[i],str[i]=str[i+1],str[i+1]=temp);
}

int main()
{
string str[3]={"China","U.S.A","Germany"};
int i;
sortStr(str);
for (i=0;i<=2;i++)cout<<str[i]<<endl;
return 0;
}
