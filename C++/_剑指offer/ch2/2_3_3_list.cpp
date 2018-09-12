
#include<iostream>
#include<cstdlib>
#include<stack>

using namespace std;

struct ListNode
{
    int nValue;
    ListNode* pNext;//=nullptr;
    ListNode(x):nValue(x),pNext(nullptr);
};

//�������ĩβ���һ�����
void add_to_tail(ListNode **pHead, int value)
{
    ListNode* pNew = new ListNode;
    pNew->nValue = value;
    if((*pHead)==nullptr)
        *pHead = pNew;
        //������Ҫ����ͷָ�룬�����Ҫ���ж�**pHead���в���
    else
    {
        //ע�����ﲻ���� auto pNode = pHead
        //��pNode��pHead����ָ��ͷ�ڵ�ָ�������ָ�����
        //��pNode���в������൱��һֱ�ڸı�ͷ�ڵ��е�����
        //����������������е��Ǳ���ͷ�ڵ㲻����Ҫ�·���
        //������Ҫ����ͷָ�����,ֻ�ǽ�����ֵ������Ӧ�ĸı�
        auto pNode = *pHead;
        //decltype(pHead) pNode;
        while(pNode->pNext!=nullptr)
            pNode=pNode->pNext;
        pNode->pNext = pNew;
    }
}

//��������ɾ����Ӧֵ�Ľ��
void remove_node(ListNode **pHead, int value)
{
    if(*pHead==nullptr || pHead==nullptr) return;
    else
    {
        ListNode* pToDeleteNode = nullptr;
        if((*pHead)->nValue == value)       //���ͷ��㼴Ҫ���ҵ�Ŀ��
        {
            pToDeleteNode = *pHead;
            *pHead=(*pHead)->pNext;
        }
        else
        {
            auto pNode = *pHead;
            while(pNode->pNext != nullptr)  //�����м��ҵ�Ҫɾ����Ŀ����
            {
                if(pNode->pNext->nValue==value)
                {
                    pToDeleteNode = pNode->pNext;
                    pNode->pNext = pToDeleteNode->pNext;
                }
                else
                {
                    pNode=pNode->pNext;
                }
            }
        }
        if(pToDeleteNode)
        {
            delete pToDeleteNode;
            pToDeleteNode = nullptr;
        }
    }
}

//�Ƚ��������ջʵ��
//���ı�pHead��ֵ,��˲��õ�ָ�뼴��
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    stack<ListNode*> nodes;

    auto pNode = pHead;
    //���Ԫ����ջ
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->pNext;
    }

    //���Ԫ�س�ջ
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout<<(pNode->nValue)<<endl;
        nodes.pop();
    }
}

int main()
{
    //����ͷ�ڵ�
    ListNode* pHead=nullptr;

    int value;
    while(cin>>value)
    {
        add_to_tail(&pHead,value);
    }
    PrintListReversingly_Iteratively(pHead);
    return 0;
}
