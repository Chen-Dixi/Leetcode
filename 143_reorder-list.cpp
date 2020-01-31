#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        
        stack<ListNode*> stc;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        if(head==NULL)
            return;

        

        while(ptr2!=NULL && ptr2->next!=NULL){ //最后ptr1就会指向最终最后的一个节点
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
        }
        ListNode* last = ptr1;
        //把ptr1之后的节点压栈
        while(ptr1->next!=NULL){
            stc.push(ptr1->next);
            ptr1 = ptr1->next;
        }

        ptr1 = head;
        while(!stc.empty()){
            ptr2 = stc.top();
            stc.pop();
            ptr2->next = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = ptr2->next;
        }

        
        last->next=NULL;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    ListNode *next = new ListNode(2);
    
    head->next = next;
    
    next->next = new ListNode(3);
    next = next->next;
    
    next->next = new ListNode(4);
    next = next->next;

    next->next = new ListNode(5);
    next = next->next;
    
    Solution sol = Solution();
    sol.reorderList(head);

    while(head!=NULL){
        printf("%d\n",head->val );
        head=head->next;
    }
    

}
