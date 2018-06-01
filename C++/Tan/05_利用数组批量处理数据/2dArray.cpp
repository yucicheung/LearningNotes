#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
int a[3][4]={{1},{5},{9}},i,j;
for(i=0;i<=2;i++){for(j=0;j<=3;j++)cout<<setw(8)<<a[i][j];}
return 0;
}
