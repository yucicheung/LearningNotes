//快速排序(默认从小到大排列)
//选择一个基准值arr[0]
//排序后将小于基准值的元素放在其左边，将大于基准值的元素放在其右边
//平均复杂度为O(nlogn)，最坏的复杂度是O(n*2)
#include<iostream>
using namespace std;

void quick_sort(int input[],int low, int high)
{
    if(low>=high) return;
    int pivot=input[high];
    int highIndex = high-1,lowIndex = low;
    int tmp;
    while(lowIndex<highIndex)
    {
        tmp=input[highIndex];
        if(tmp>pivot)
            --highIndex;
        else
        {
            input[highIndex]=input[lowIndex];
            input[lowIndex]=tmp;
            ++lowIndex;
        }
    }
    int swapIndex = (pivot<input[lowIndex])?lowIndex:(lowIndex+1);
    tmp = input[swapIndex];
    input[swapIndex] = pivot;
    input[high] = tmp;

    //devide and conquer
    quick_sort(input,lowIndex+1,high);
    quick_sort(input,low,lowIndex-1);
}

int main()
{
    int input[]={7,6,5,4,3,2,1};
    quick_sort(input,0,4);
    for(auto i:input)
        cout<<i<<endl;
    return 0;
}
