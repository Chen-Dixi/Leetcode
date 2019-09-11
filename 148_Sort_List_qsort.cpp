
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* endpoint = head;
        while (endpoint->next){
            endpoint = endpoint->next;
        } 

        QuickSort (head,endpoint);
        
        return head;
    }
private:
    void QuickSort(ListNode * pStart, ListNode *pEnd){
        if(pStart != pEnd){
            ListNode * partition
        }
    }
};
