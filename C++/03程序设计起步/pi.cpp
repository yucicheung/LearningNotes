#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
int sign=1;
double lastItem=1,pi=0,n=1;
//cout<<sizeof(double);
//cout<<sizeof(int);
while(fabs(lastItem)>=1e-7)
{
pi+=lastItem;
sign*=-1,n+=2,lastItem=sign/n;
}
cout<<(pi*=4)<<endl;
return 0;
}
