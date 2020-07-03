class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr || pHead->next==nullptr)
            return pHead;
        ListNode* next = pHead->next;
        if(pHead->val == next->val){
            while(next!=nullptr && pHead->val==next->val)
                next = next->next;
            return deleteDuplication(next);
        }else{
            pHead->next = deleteDuplication(pHead->next);
            return pHead;
        }
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //
        if(pHead==nullptr || pHead->next==nullptr)
            return pHead;

        ListNode* next = pHead->next;

        //从开头到接下来就是一样的节点
        if(pHead->val == next->val)
        {
            while(next->next!=nullptr && pHead->val!=next->val)
                next = next->next;

            return deleteDuplication(next);
        }else{
            pHead->next = deleteDuplication(next);
            return pHead;
        }
    }
};