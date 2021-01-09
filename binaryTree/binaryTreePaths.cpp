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

    void binaryTreePaths(TreeNode* root,vector<string>&ret, string str){
        if(!root->left && !root->right){str+=root->val;ret.push_back(str);}

        string s = str + to_string(root->val) + "->";
        if(root->left)binaryTreePaths(root->left,ret,s);
        if(root->right)binaryTreePaths(root->right,ret,s);
    }
    public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        
        binaryTreePaths(root,ret,"");
        return ret;
    }
};