#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unordered_map>
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
        
        ListNode* cur=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;

        while(cur!=nullptr){
            next=cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};