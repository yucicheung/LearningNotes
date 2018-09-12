/*
lambda函数的使用
typedef的基本使用
*/
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100;
int arri[maxn]{4,5,2,3,7,8};

typedef uint32_t myint;
int main()
{
    //[]中表示被捕获的值
    //lambda表达式如果要使用函数体外定义的变量，就需要对之进行捕获
    //如果是[]表示不能运用函数外的变量
    //[=]表示值捕获
    //[&]表示引用捕获
    sort(arri,arri+6,[](int x,int y){return x>y;});
    for(int i:arri)printf("%d\n",i);
    myint a=2;
    printf("%d",a);
    return 0;
}
