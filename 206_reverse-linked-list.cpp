#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <cstdint>
#include <algorithm>
using namespace std;

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
    ListNode* reverseList(ListNode* head) {
        
        ListNode * prev=NULL;
        ListNode * cur=head;

        while(cur!=NULL){
            List next = cur->next;
            cur->next = prev;
            prev = cur;
            cur=next;
        }
        return prev;
    }
};