#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)
            return nullptr;

        ListNode* ptr1 =head;
        ListNode* ptr2 = getIntersect(head);

        if(ptr2==nullptr)
            return nullptr;

        while(ptr2!=ptr1){
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }

        return ptr2;
    }
private:
    ListNode *getIntersect(ListNode *head){
        ListNode* kuai=head;
        ListNode* man=head;
        while(kuai!=nullptr && kuai->next!=nullptr){
            kuai = kuai->next->next;
            man = man->next;
            if(kuai==man){
                return kuai;
            }
        }
        return nullptr;
    }
};