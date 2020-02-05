#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <vector>
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

//===递归解法

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //反转从m到n的链表节点，部分反转
        //这不是一种插入重新排列，完全从头到尾调换顺序，还是和之前的题不一样
        if (m==1){
            return reversN(head, n);
        }

        
        head->next = reverseBetween(head->next, m-1,n-1);
        return head;
    }

    ListNode * reversN(ListNode* head, int n){
        if (n==1){
            successor = head->next;
            return head;
        }   
        ListNode* last = reversN(head->next,n-1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
private:
    ListNode* successor;
};

class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        
        if (head==NULL){
            return NULL;
        }

        ListNode *con = head;
        ListNode *tail = NULL;
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *third = NULL;

        while(--m){
            prev = cur;
            cur = cur->next;
            n--;
        }

        tail = cur;//确定尾部
        con = prev;//确定头部

        while(n--){
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur=third;
        }
        if(con!=NULL){
            con->next = prev;
        }else{
            head = prev;
        }
        tail->next = cur;
        
        return head;
    }

};




