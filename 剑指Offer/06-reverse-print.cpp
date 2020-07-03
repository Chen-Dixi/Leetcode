#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
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
    vector<int> reversePrint(ListNode* head) {

        vector<int> ans;
        help(ans,head);
        return ans;
    }
    //栈和递归
    void help(vector<int> & ans, ListNode* head){
        if(head==nullptr)
            return;

        if(head->next!=nullptr){
            help(ans,head->next);
        }
        ans.push_back(head->val);
    }
};

//栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        stack<int> stc;
        while(head!=nullptr){
            stc.push(head->val);
            head=head->next;
        }
        while(!stc.empty()){
            ans.push_back(stc.top());
            stc.pop();
        }
        return asn;
    }
};