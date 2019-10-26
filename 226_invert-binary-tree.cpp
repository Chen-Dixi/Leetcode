#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
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
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == NULL){
            return;
        }

        invertTree(root->right)
        invertTree(root->left)

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
};

int main(){
    Solution sol = Solution();
    
    
}