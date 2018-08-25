#include<stdio.h>
#include<tchar.h>
class A{
private:
    int value;

public:
    A(int n):value(n){}
    A(A& other):value(other.value){}
    void print(){printf("%d\n",value);}
};
int _tmain(int argc,_TCHAR* argv[])
{
    A a(3);
    A b(a);
    b.print();
    return 0;
}
