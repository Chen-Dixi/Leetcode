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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        

        ListNode* ptr1=headA;
        ListNode* ptr2=headB;

        while(ptr2!=ptr1){
            if(ptr2->next==nullptr) //错误，需要走到nullptr的情况，若果不相交，同时走到m+n就都等于null了；
                ptr2=headA;
            else
                ptr2=ptr2->next;
            if(ptr1->next==nullptr)
                ptr1=headB;
            else
                ptr1=ptr1->next;
        }
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            if(node1==nullptr)
                node1 = headB;
            else
                node1=node1->next;
            if(node2 == nullptr)
                node2=headA;
            else
                node2=node2->next;

            if(node1==nullptr && node2==nullptr)
                return nullptr;
        }
        return node1;
    }
};
