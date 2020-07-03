#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <sstream>
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        ostringstream out;
        serializeOstream(root, out);
        
        return out.str();
    }

    void serializeOstream(TreeNode* root, ostringstream & out){
        if(root==nullptr){
            out<<"null ";
            return;
        }

        out<<root->val<<" ";
        serializeOstream(root->left, out);
        serializeOstream(root->right,out);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        TreeNode* root = deserializeIstream(is);
        return root;
    }

    TreeNode* deserializeIstream(istringstream & is){
        string val;
        is>>val;
        if(val=="null"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeIstream(is);
        root->right = deserializeIstream(is);
        return root;
    }
};