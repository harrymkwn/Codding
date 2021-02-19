#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    void tree2str(TreeNode*root ,string &str){
        if(!root)return;
        if(!root->left && !root->right){str += to_string(root->val);return;}
        str += to_string(root->val) + "(";
        if(root->left)tree2str(root->left,str);
        if(root->right)tree2str(root->right,str);
    }

public:
    string tree2str(TreeNode* t) {
        string str="";
        tree2str(t,str);
        return str;
    }
};