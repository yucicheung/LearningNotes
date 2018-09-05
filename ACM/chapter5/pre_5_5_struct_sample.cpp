#include<iostream>
using namespace std;

template <typename T>
struct Point{
    T x,y;
    Point(T x=0,T y=0):x(x),y(y){}
};

//ע�ⷵ�����Ͳ���ʹ����������
//�������ں����ڲ�����ģ�����ʱ���pass by reference������������ʵ������Ч
//����ԭ���ô��룬��ԭ���ô���
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
