#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
void sort(int*,int*);
int a,b;
int *pa,*pb;
pa=&a,pb=&b;
cout<<"Input a and b:"<<endl;
cin>>*pa>>*pb;
if (*pa>*pb) swap(pa,pb);
cout<<"min="<<*pa<<" max="<<*pb<<endl;
return 0;
}
void swap(int* pa,int* pb)
{
int tmp;
tmp = *pa;
*pa = *pb;
*pb = tmp;
}
