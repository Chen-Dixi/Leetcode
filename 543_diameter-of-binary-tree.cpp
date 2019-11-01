#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <climits>
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
    int maxans=0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL)
            return 0;
        int left_ans = find(root->left);
        int right_ans = find(root->right);

        maxans = max(left_ans+right_ans, maxans);

        return maxans;
    }

    int find(TreeNode* root){
        if (root==NULL)
            return 0;
        int left_ans = find(root->left);
        int right_ans = find(root->right);

        maxans = max(left_ans+right_ans, maxans);

        return max(left_ans, right_ans)+1;
    }
};


int main(){
    
}
