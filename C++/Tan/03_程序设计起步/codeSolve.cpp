#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
char c;
int index,i;
char table[52];
for(i=0;i<=21;i++) table[i]='E'+i;
for(i;i<=25;i++) table[i]='A'+i-22;
for(i;i<=47;i++) table[i]='e'+(i-26);
for(i;i<=51;i++) table[i]='a'+(i-48);
while((c=getchar())!='\n')
	{
	if(c>='A'&&c<='Z') cout<<table[c-'A'];
	else if(c>='a'&&c<='z') cout<<table[c-'a'+26];
	else cout<<c;
	}
cout<<endl;
return 0;
}
