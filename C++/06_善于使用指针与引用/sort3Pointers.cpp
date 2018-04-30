#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
void sort(int *,int*,int*);
int a,b,c,*pa=&a,*pb=&b,*pc=&c;
cout<<"Input a b c:";
cin>>*pa>>*pb>>*pc;
sort(pa,pb,pc);
cout<<"from smallest to largest:"<<*pa<<','<<*pb<<','<<*pc<<endl;
return 0;
}
void sort(int *pa,int *pb,int *pc)
{
void swap(int*,int*);
if (*pa>*pb) swap(pa,pb);
if (*pa>*pc) swap(pa,pc);
if (*pb>*pc) swap(pb,pc);
}
void swap(int *p1,int *p2)
{int tmp;
tmp=*p1,*p1=*p2,*p2=tmp;
}
