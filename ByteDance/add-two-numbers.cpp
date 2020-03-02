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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum=0;
        int jinwei=0;
        int a,b;
        ListNode* head=new ListNode(0);
        ListNode* n=head;

        while(l1!=NULL || l2!=NULL){
            n->next = new ListNode(0);
            if(l1!=NULL){
                a=l1->val;
                l1=l1->next;
            }else{
                a=0;
            }

            if(l2!=NULL){
                b=l2->val;
                l2=l2->next;
            }else{
                b=0;
            }

            int tmp = a+b+jinwei;
            if(tmp>=10){
                jinwei=1;
            }else{
                jinwei=0;
            }

            
            n=n->next;
            n->val= tmp % 10;

        }
        if(jinwei==1){
            n->next = new ListNode(1);
        }
        return head->next;
    }
};