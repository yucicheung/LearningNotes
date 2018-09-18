//优先队列按照权值排序（底部容器+heap算法实现一个堆）
//权值最大的先出列
#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector<int> iVec{23,455,67,78};
    priority_queue<int> iPq(iVec.begin(),iVec.end());
    int loopNum = iPq.size();
    for(int i=0;i<loopNum;i++)
    {
        cout<<iPq.top()<<endl;
        iPq.pop();
    }
    return 0;
}
