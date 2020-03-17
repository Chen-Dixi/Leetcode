#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;
//蓄水池抽样
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = this->head->val;
        ListNode* next = head->next;
        int i=2;
        while(next!=NULL){
            int val = next->val;
            int j=rand()%i;
            if(j==0){
                res=val;
            }
            i++
            next = next->next;
        }
        return res;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */