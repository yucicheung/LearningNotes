//���ȶ��а���Ȩֵ���򣨵ײ�����+heap�㷨ʵ��һ���ѣ�
//Ȩֵ�����ȳ���
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
