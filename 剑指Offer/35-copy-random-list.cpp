#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        Node* cur=head;
        //step1
        while(cur!=nullptr){
            Node* acopy = new Node(cur->val);
            acopy->next = cur->next;
            cur->next = acopy;
            cur = acopy->next;
        }

        //step2
        cur=head;
        while(cur!=nullptr){
            if(cur->random!=nullptr){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        //step3
        cur=head;
        Node* copyCur=cur->next;
        Node* copyhead=cur->next;
        cur->next = copyCur->next;
        cur = cur->next;

        while(cur!=nullptr){
            copyCur->next = cur->next;
            copyCur = copyCur->next;
            cur->next = copyCur->next;
            cur = cur->next;
        }

        return copyhead;

    }
};