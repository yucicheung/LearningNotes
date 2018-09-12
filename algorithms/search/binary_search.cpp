//在有序列表中，已经有序排列的数组
//取中间记录为查找对象，如果查找值大于它，则在其右区间内
//给定值总与所在区间的中间
#include<iostream>
using namespace std;

int binary_search_in(int *a,int n,int key)
{
    if(n==0 || a==nullptr) return -1;
    int low =0, high = n-1;
    int  mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==key) return mid;
        else if(a[mid]>key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    int a[50]= {1,2,3,4};
    int n=4;
    int key=1;
    cout<<binary_search_in(a,n,key)<<endl;
    return 0;
}
