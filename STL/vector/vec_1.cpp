/*
vector是连续的线性空间
普通指针就可以作为vector的迭代器
支持随机存取，不同于array是静态空间，vector会自动扩容
当vector的容量超过其size时，容量会被扩充，大致是放大两倍
容量扩张是：重新配置、元素移动、释放原空间

vector的end()返回最后一个元素的下一个元素位置
*/
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> veci(3,8);
    cout<<veci.size()<<endl;
    cout<<veci.capacity()<<endl;
    veci.push_back(3);
    cout<<veci.size()<<endl;
    cout<<veci.capacity()<<endl;
    cout<<(veci.end()-veci.begin())<<endl;
    cout<<veci.front()<<"  "<<veci.back()<<endl;
    vector<int>::iterator vi=veci.begin();
    printf("%d\n",vi);
    printf("%d\n",vi[veci.size()-1]);
    printf("%d\n",veci.empty());
    printf("%d\n",veci.size());
    printf("%d\n",veci.begin());
    printf("%d\n",veci.end());
    return 0;
}
