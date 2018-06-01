#include <iostream>
#include <string.h>
using namespace std;

int main()
{
int i;
char nation[3][20]={{"GERMANY"},{"FRENCH"},{"CHINA"}};
char *smallestStr= nation[0];
//smallestStr=nation[0];//const value can not be assigned value
for (i=1;i<=2;i++) (strcmp(smallestStr,nation[i])<0) ? smallestStr :(smallestStr=nation[i]);//notice in :? two types must be the same
cout<<smallestStr<<endl;
return 0;
}
