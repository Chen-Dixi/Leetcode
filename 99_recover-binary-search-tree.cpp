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
        if (pre!=NULL && root->val < pre->val){
            if(t1==NULL) t1=pre;
            t2=root;
        }
        pre = root;
        inorderTraversal(root->right);
    }
};

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

作者：ZZYuting
链接：https://leetcode-cn.com/problems/recover-binary-search-tree/solution/cliang-chong-fang-fa-1shi-yong-di-gui-de-zhong-xu-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){
    return 0;
}