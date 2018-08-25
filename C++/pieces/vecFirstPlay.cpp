#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;
void swapVec(vector<int>& a)
{
    for(int i=0;i<a.size()/2;i++)
    {
        int j = a.size()-i-1;
        cout<<j<<endl;
        int mid = a[j];
        a[j]=a[i];
        a[i]=mid;
    }
}

void printVec(vector<int> & a)
{
    for(int i =0;i<=1;i++)
    cout<<a[i]<<endl;
}
int main()
{
    int a[]={1,2,3,4,5,6};
    vector<int> vec(a,a+2);
    swapVec(vec);
    printVec(vec);
    return 0;
}
