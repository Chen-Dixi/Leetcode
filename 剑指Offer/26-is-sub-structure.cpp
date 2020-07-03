#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool res = false;
        if(A!=nullptr && B!=nullptr){
            if(A->val==B->val){
                res = judge(A,B);
            }
            if(!res){
                res=isSubStructure(A->left, B);
            }
            if(!res){
                res=isSubStructure(A->right, B);
            }
        }   
        return res;
    }
    //这里的子树并不要求完全一样，可以部分包含
    bool judge(TreeNode* root1, TreeNode* root2){

        if(root2==nullptr)
            return true;
        if(root1==nullptr)//root2!=nullptr, root1==nullptr
            return false;
        return root1->val == root2->val && judge(root1->left, root2->left) && judge(root1->right, root2->right);
        
    }
};