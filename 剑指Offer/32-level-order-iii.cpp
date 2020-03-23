#include <stack>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <unordered_map>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        stack<TreeNode*> stc[2];
        
        int current = 0;
        int next = 1;
        stc[0].push(root);
        vector<int> a;
        
        
        while(!stc[0].empty() || !stc[1].empty()){
            TreeNode* top = stc[current].top();stc[current].pop();
            a.push_back(top->val);

            if(current==0){//从左往右
                if(top->left!=nullptr)
                    stc[next].push(top->left);
                if(top->right!=nullptr)
                    stc[next].push(top->right);
            }else{//从右往左
                if(top->right!=nullptr)
                    stc[next].push(top->right);
                if(top->left!=nullptr)
                    stc[next].push(top->left);
            }

            if(stc[current].empty()){
                res.push_back(a);
                a.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }

        return res;
    }
};

