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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prevHead = ListNode(-1);
        ListNode* cur = prevHead;

        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<l2->val){
                cur->next = l1;
                l1=l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
        }
        if(l1!=nullptr)
            cur->next = l1;
        if(l2!=nullptr)
            cur->next = l2;

        return prevHead->next
    }
};

//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode* head;
        if(l1->value<l2->value){
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }else{
            head = l2;
            head->next = mergeTwoLists(l1,l2->next);
        }
        return head;
    }
};