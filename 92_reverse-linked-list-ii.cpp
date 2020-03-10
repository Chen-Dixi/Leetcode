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
        
        if(head==NULL)
            return NULL;

        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* tail=NULL;
        ListNode* third=NULL;
        ListNode* con=NULL;

        while(--m){
            prev=cur;
            cur=cur->next;
            n--;
        }

        con = prev; //反转这一段链表，反转后头部跟在con后面，如果从第一个节点开始反转，con==NULL
        tail = cur; //此时，tail是要反转这一段的头部，反转过后会变成尾部，所以是tail

        while(n--){
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
        }

        if(con==NULL){
            head = prev;
        }else{
            con->next = prev;
        }

        tail->next = cur;

        return head;

    }

};

//简单的反转链表
class Solution4Simple {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL){
            return NULL;
        }

        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* third = NULL;

        while(cur!=NULL){
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
        }
        return prev;
    }
};


