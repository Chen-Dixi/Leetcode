#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
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
    
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right);
    }
};

int main(){
    Solution sol = Solution();
    int n=10;
    int ans = sol.climbStairs(n);
    printf("%d\n",ans );
    return 0;
}