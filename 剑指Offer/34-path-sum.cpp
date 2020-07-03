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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        search(root, res, path, 0, sum);
        return res;
    }

    void search(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int cur, int sum ){
        
        if(root==nullptr)
            return;

        
        
        path.push_back(root->val);

        if(cur+(root->val) == sum && root->left==NULL && root->right==NULL){
            res.push_back(path);
            path.pop_back();
            return;
        }

        
        search(root->left,res,path,cur+(root->val),sum);
        search(root->right,res,path,cur+(root->val),sum);
        
        path.pop_back();
    }
};