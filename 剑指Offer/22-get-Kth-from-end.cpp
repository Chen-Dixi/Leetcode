#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==nullptr||k<=0)
            return nullptr;      

        ListNode* ahead=head;
        ListNode* behind=head;

        for(int i=0;i<k-1;i++){
            if(ahead->next==nullptr)
                return nullptr;
            ahead = ahead->next;

        }

        while(ahead->next!=nullptr){
            ahead=ahead->next;
            behind = behind->next;
        }

        return behind;
    }
};