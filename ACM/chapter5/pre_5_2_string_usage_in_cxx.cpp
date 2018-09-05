#include <iostream>
using namespace std;


int Binary_Search(int Array[], int len, int key)
{
    if(0 == len)
        return -1;
    int left = 0;
    int right = len -1;
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(key == Array[mid])
            return mid;
        else if(Array[mid] < key)
            left = mid+1;
        else if(Array[mid] > key)
            right = mid;
    }
    return -1;
}

int main()
{
    int Array[5] = {1,2,3,4,5};
    cout << Binary_Search(Array,5,4.5) << endl;
    return 0;
}
