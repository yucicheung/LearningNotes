/*
vector�����������Կռ�
��ָͨ��Ϳ�����Ϊvector�ĵ�����
֧�������ȡ����ͬ��array�Ǿ�̬�ռ䣬vector���Զ�����
��vector������������sizeʱ�������ᱻ���䣬�����ǷŴ�����
���������ǣ��������á�Ԫ���ƶ����ͷ�ԭ�ռ�

vector��end()�������һ��Ԫ�ص���һ��Ԫ��λ��
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
