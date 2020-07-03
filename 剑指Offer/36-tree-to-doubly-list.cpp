#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <cstdint>
#include <algorithm>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* head = nullptr, *pre = nullptr;
        helper(root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void helper(Node* root, Node*& head, Node*& pre) {
        if(!root)  return;
        helper(root->left, head, pre);
        if(!head) {
            head = root;   // 找到head
            pre = root;    // 对pre进行初始化
        } else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        helper(root->right, head, pre);
    }
};

//剑指Offer的书
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* head = nullptr, *pre = nullptr;
        helper(root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void helper(Node* root, Node*& head, Node*& pre) {
        if(!root) return;

        //中序遍历，处理好的效果，从小到大
        helper(root->left,head,pre);
        if(pre==nullptr){
            head=root;
            pre=root;
        }else{
            pre->right=root;
            root->left=pre;
            pre=root;
        }
        helper(root->right, head, pre);
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* head = nullptr, *pre = nullptr;
        helper(root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void helper(Node* root, Node*& head, Node*& pre){
        if(root==nullptr)
            return;

        helper(root->left, head, pre);
        if(pre==nullptr){
            head=root;
            pre=root;
        }else{
            root->left=pre;
            pre->right=root;
            pre=root;
        }
        helper(root->right, head, pre);
    }
};
/*
class Solution {
public:
    Node* head=NULL;
    Node* last=NULL;
    Node* treeToDoublyList(Node* root) {
        if(!root)return root;
        inorder(root);
        head->left = last;      //首尾相连
        last->right = head;
        return head;
    }
    void inorder(Node* root){
        if(!root)return ;
        inorder(root->left);
        if(!last){
            last = root;
            head = root;
        }else{
            last->right = root;
            root->left = last;
            last = root;
        }
        inorder(root->right);
    }
};
*/