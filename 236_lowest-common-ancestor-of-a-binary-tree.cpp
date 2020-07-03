#include <iostream>
#include <stack>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 最近公共祖先，that is to say, 1. 节点p 和 q分别在这个祖先节点的两边。 2. 祖先节点是p,q其中之一
        
        TreeNode* ancestor = NULL;
        dfs(root, p, q, ancestor); //这样就可一改变它的值了

        return ancestor;
    }

    // 深度遍历，返回bool标记
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ancestor){
        bool right = false, left = false;

        if (root==NULL){
            return false;
        }

        left = dfs(root->left, p , q, ancestor); //在左边有找到 p 或 q
        right = dfs(root->right, p , q, ancestor); //在右边有找到 p 或 q
        
        if((left && right) || ((left || right) && (root==p || root==q)))
           ancestor = root;

        if(root == p || root == q || left || right)
            return true;
        else
            return false;
    }
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 最近公共祖先，that is to say, 1. 节点p 和 q分别在这个祖先节点的两边。 2. 祖先节点是p,q其中之一
        
        if(root==nullptr || root==p || root = q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right)
            return root;


        return left==nullptr? right : left;
    } 
}

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root TreeNode* p, TreeNode* q){
        TreeNode* ancestor = nullptr;
        dfs(root, p ,q, ancestor);

        return ancestor;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ancestor){
        bool right = false, left = false;
        if(root==nullptr){
            return false;
        }

        left = dfs(root->left, p ,q ,ancestor);
        right = dfs(root->right, p ,q ,ancestor);

        if((left&&right) || (root->val==p->val || root->val==q->val) && (left || right))
            ancestor = root;

        return left || right || (root->val==p->val) || root->val==q->val;

    }
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 最近公共祖先，that is to say, 1. 节点p 和 q分别在这个祖先节点的两边。 2. 祖先节点是p,q其中之一
        
        stack<pair<TreeNode*, int> > s;
        // 0 both pending; 1 left done; 2 both done

        pair<TreeNode*,int> tmp = make_pair(root, 2);
        TreeNode *LCA = NULL;
        TreeNode *child_node=NULL;
        s.push(tmp);
        bool one_node_found = false;
        while(!s.empty()){
            pair<TreeNode*,int> top = s.top();
            TreeNode * parent_node = top.first;
            int parent_state = top.second;
            // If the parent_state is not equal to BOTH_DONE,
            // this means the parent_node can't be popped off yet.
            if(parent_state!=0){
                if (parent_state == 2){
                    if (parent_node == p || parent_node == q){
                        if(one_node_found)//如果已经发现过一个
                            return LCA;
                        else{
                            one_node_found=true;
                            LCA = s.top().first;

                        }
                    }
                    child_node = parent_node->left;
                }else{
                    child_node = parent_node->right;
                }
                s.pop();
                s.push(make_pair(parent_node,parent_state-1));   
                // Add the child node to the stack for traversal.
                if (child_node != NULL) {
                    s.push(make_pair(child_node, 2));
                }

            }else{
                TreeNode* tmp = s.top().first;
                s.pop();
                if (LCA==tmp && one_node_found){
                    LCA=s.top().first;

                }
            }
        }
        return NULL;  
    }
    
};





