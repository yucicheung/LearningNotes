/*
问题：一个水王发帖数目超过了帖子总数的一半，如果当前一个论坛上所有帖子的列表，包括作者ID也在表中，如何快速找出水王
分析：
<方案一>
ID列表如果是有序的，且水王发帖数超过了帖子总数的一半，那么ID列表(从0开始编号)中的第N/2项一定会是这个水王的ID，因此判断操作的时间复杂度为O(1)
<方案二>
为了避免排序，每次删除列表中两个不同的元素，在剩下的ID中，水王的比例仍旧会超过一半，不断重复此过程，可以将ID列表总数降低，从而得到答案
总的时间复杂度是O(N)，且只需要常数的额外内存。
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    //方案1
    vector<int> iVec{1,2,2,2,2,4,5,0,3,5};
    sort(iVec.begin(),iVec.end());
    cout<<iVec[iVec.size()/2]<<endl;
    return 0;
}
