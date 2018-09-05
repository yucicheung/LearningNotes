#include<stdio.h>
#include<math.h>

typedef struct Point
{
public:
    double x,y;
/*public:
    Point(double a,double b):x(a),y(b)
    {}*/
}Point;

double hypot(double difa,double difb)
{
    return sqrt(difa*difa+difb*difb);
}

double dist(Point a, Point b)
{
    return hypot((a.x-b.x),(a.y-b.y));
}

int main()
{
    double a,b;
    Point point{a,b};
    return 0;
}
