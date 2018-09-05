#include<iostream>
using namespace std;

template <typename T>
struct Point{
    T x,y;
    Point(T x=0,T y=0):x(x),y(y){}
};

//注意返回类型不能使用引用类型
//变量是在函数内部定义的，返回时如果pass by reference，传出的引用实际上无效
//除非原引用传入，再原引用传出
template <typename T>
Point<T> operator+(const Point<T>& point1, const Point<T>& point2)
{
    return Point<int>(point1.x+point2.x,point1.y+point2.y);
}

template <typename T>
ostream& operator<<(ostream& out,Point<T>& point)
{
    out<<'('<<point.x<<','<<point.y<<')';
    return out;
}

int main()
{
    Point<int> pointa(12,20);
    Point<int> pointb(3,4);
    Point<int> pointc(1,2);
    cout<<pointa<<endl;
    cout<<pointb<<endl;
    pointa=pointa+pointb+pointc;
    cout<<pointa<<endl;
    return 0;
}
