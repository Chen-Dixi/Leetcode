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
    
    vector<vector<int> > paths;
    
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        if (root!=NULL)
            dfs(root,0,sum,path);
        return paths;
    }
    
    void dfs(TreeNode* root, int current, int sum, vector<int> path ){

        path.push_back(root->val);
        current+=(root->val);

        // if (current>sum)
        //     return;//减枝

        if (isLeaf(root)){
            if (current==sum)
                paths.push_back(path);
            return;
        }

        if(root->left!=NULL){
            dfs(root->left, current,sum, path);
        }
        if(root->right!=NULL){
            dfs(root->right, current,sum, path);
        }
    }

    bool isLeaf(TreeNode* root){
        return root->left == NULL && root->right == NULL;
    }
    
    
};