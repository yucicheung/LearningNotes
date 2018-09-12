#include<vector>
#include<stack>
using namespace std;


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        auto node = head;//һ��ͷָ���ǲ�������Ӧ��ֵ���ݵ�
        stack<int> nodesStack;
        while(node != NULL)
        {
            nodesStack.push(node->val);
            node = node->next;
        }
        vector<int> ret;
        while(!nodesStack.empty())
        {
            ret.push_back(nodesStack.top());
            nodesStack.pop();
        }
        return ret;
    }
};
