#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL || l2==NULL){
            if(l1!=NULL)
                return l1;
            else if(l2!=NULL)
                return l2;
            else 
                return NULL;
        }

        ListNode* res = new  ListNode(0);
        ListNode* h = res;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                h->next = l1;
                l1=l1->next;
            }else{
                h->next = l2;
                l2=l2->next;
            }
            h = h->next;
        }

        h->next = (l1==NULL) ? l2 : l1;

        return res->next;
    }
};