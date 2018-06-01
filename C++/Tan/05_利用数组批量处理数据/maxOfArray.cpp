#include<iostream>
#include<iomanip>
//#include<tuple>
using namespace std;
int maxInArray(int a[][4])//,int width,int height)
{
int width = 3,height=4;
int i,j,row=0,col=0,max=a[0][0];
for (i=0;i<width;i++)for(j=0;j<height;j++)max>a[i][j]?:(max=a[i][j],row=i,col=j);
//return tuple(max,row,col);
return max;
}

int main()
{
int a[3][4]={5,12,23,56,19,28,37,46,-12,-34,6,8};
int max,row,col;
//max,row,col = maxInArray(a,3,4);
max = maxInArray(a);
cout<<"max value is "<<max<<endl;//" pos["<<row<<"]["<<col<<']'<<endl;
return 0;

}
