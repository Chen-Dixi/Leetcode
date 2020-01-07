#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        if (root==NULL)
            return;
        TreeNode *right = root->right;

        TreeNode *next = root->left;
        if (root->left == NULL){
            flatten(root->right);
        }else{
            //
            root->left=NULL;
            root->right = next;
            while(next->right!=NULL){
                next=next->right;
            }
            next->right = right; //放在左子树最右侧

            flatten(root->right);
        }
    }
};


