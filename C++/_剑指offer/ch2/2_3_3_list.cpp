
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

//往链表的末尾添加一个结点
void add_to_tail(ListNode **pHead, int value)
{
    ListNode* pNew = new ListNode;
    pNew->nValue = value;
    if((*pHead)==nullptr)
        *pHead = pNew;
        //这里需要更换头指针，因此需要进行对**pHead进行操作
    else
    {
        //注意这里不能用 auto pNode = pHead
        //则pNode和pHead都是指向头节点指针变量的指针变量
        //对pNode进行操作，相当于一直在改变头节点中的内容
        //而在这里我们想进行的是保持头节点不再需要新分配
        //不再需要进行头指针更换,只是将它的值进行相应的改变
        auto pNode = *pHead;
        //decltype(pHead) pNode;
        while(pNode->pNext!=nullptr)
            pNode=pNode->pNext;
        pNode->pNext = pNew;
    }
}

//在链表中删除对应值的结点
void remove_node(ListNode **pHead, int value)
{
    if(*pHead==nullptr || pHead==nullptr) return;
    else
    {
        ListNode* pToDeleteNode = nullptr;
        if((*pHead)->nValue == value)       //如果头结点即要查找的目标
        {
            pToDeleteNode = *pHead;
            *pHead=(*pHead)->pNext;
        }
        else
        {
            auto pNode = *pHead;
            while(pNode->pNext != nullptr)  //链表中间找到要删除的目标结点
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

//先进后出，用栈实现
//不改变pHead的值,因此采用单指针即可
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    stack<ListNode*> nodes;

    auto pNode = pHead;
    //逐个元素入栈
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->pNext;
    }

    //逐个元素出栈
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout<<(pNode->nValue)<<endl;
        nodes.pop();
    }
}

int main()
{
    //创建头节点
    ListNode* pHead=nullptr;

    int value;
    while(cin>>value)
    {
        add_to_tail(&pHead,value);
    }
    PrintListReversingly_Iteratively(pHead);
    return 0;
}
