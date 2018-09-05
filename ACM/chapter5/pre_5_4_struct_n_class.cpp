/*
struct和class实现上差异不大
甚至struct也是一种class
*/

#include<stdio.h>

struct Example{
public:
    Example(){}

};

class Example{
public:
    Example(){}
};

int main()
{
    Example example();
    return 0;
}
