#include<stdio.h>

using namespace std;
class empty{
public:
    empty();
    virtual ~empty();
};
int main()
{
    printf("%d\n",sizeof(empty));
    return 0;
}
