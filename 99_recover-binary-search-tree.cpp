#include <iostream>
#include <vector>
#include <map>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

    void recoverTree(TreeNode* root) {
        if (root==NULL)
            return;
        inorderTraversal(root);
        if (t1!=NULL && t2!=NULL){
            int temp = t1->val;
            t1->val = t2->val;
            t2->val = temp;
        }
    }
private:
    TreeNode* pre;
    TreeNode* t1;
    TreeNode* t2;
    int flag=0;
    void inorderTraversal(TreeNode* root){
        if(root==NULL)
            return;
        inorderTraversal(root->left);
        if (pre!=NULL && root->val < pre->val){ //只是被交换，就可以这样找
            if(t1==NULL) t1=pre;
            t2=root;
        }
        pre = root;
        inorderTraversal(root->right);
    }
};

//Morris Traversal inorder
/*1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/

class Solution_Morris {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* tmp = nullptr;
        TreeNode* cur = root;
        TreeNode* pre = new TreeNode(INT_MIN);
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        while(cur!=nullptr){
            if(cur->left == nullptr){
                // printf("%d ", cur->val);
                if(first == nullptr&&pre->val > cur->val){
                    first = pre;
                }
                if(first!=nullptr&&pre->val > cur->val){
                    second = cur;
                }
                pre = cur;
                //
                cur = cur->right;
            }else{
                tmp = cur->left;
                while(tmp->right!=nullptr && tmp->right!=cur){
                    tmp = tmp->right;
                }
                if(tmp->right == nullptr){
                    tmp->right = cur;
                    cur = cur->left;
                }else{
                    tmp->right = nullptr;
                    // printf("%d ", cur->val);
                    if(first == nullptr&&pre->val > cur->val){
                        first = pre;
                    }
                    if(first!=nullptr&&pre->val > cur->val){
                        second = cur;
                    }
                    pre = cur;
                    //
                    cur = cur->right;
                }
            }
        }
        int t=first->val;
        first->val = second->val;
        second->val = t;
    }
};

int main(){
    return 0;
}