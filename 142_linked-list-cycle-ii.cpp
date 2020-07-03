#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = getIntersect(head);

        if (ptr2==NULL)
            return NULL;

        while(ptr2!=ptr1){
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }

        return ptr2;
    }

private:

    ListNode *getIntersect(ListNode *head){

        ListNode *man = head;
        ListNode *kuai = head;

        //man = man->next;
        //kuai = kuai->next->next;//这样写有问题
        while(kuai!=NULL && kuai->next!=NULL){
            kuai = kuai->next->next;
            man = man->next;
            if(kuai==man)
                return kuai;
        }

        return NULL;
    }
};

int main(){

}