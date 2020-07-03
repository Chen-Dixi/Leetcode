#include <iostream>
#include <cstdio>
#include <cstring>
using namespacce std;

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode->right!=nullptr){
            TreeLinkNode * left = pNode->right;
            while(left->left!=nullptr){
                left = left->left;
            }
            return left;
        }else{
            while(pNode->next!=nullptr){
                if(pNode->next->left==pNode){
                    return pNode->next;
                }
                pNode=pNode->next;
            }
        }
        return nullptr;
    }
};