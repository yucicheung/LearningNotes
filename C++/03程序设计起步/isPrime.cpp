#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int num)
{bool prime=true;
int i;
int endNum=int(sqrt(num));
for(i=2;i<=endNum;i++){if(num%i==0){prime=false;break;}}
return prime;
}

int main()
{
int num=101;
bool prime;
while(num<200)
	{
	if(prime=isPrime(num))cout<<num<<endl;
	num+=2;
	}
return 0;
}
