#include<iostream>
using namespace std;
namespace ns1
{
const int RATE=0.88;
double pay=100;
double tax()
	{return pay*RATE;}
namespace ns2
	{int age=23;}
}

//using namespace ns1;
int main()
{
cout<<ns1::RATE<<endl;
cout<<ns1::pay<<endl;
cout<<ns1::tax()<<endl;
cout<<ns1::ns2::age<<endl;
return 0;
}
