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
public:

    bool validate(TreeNode* root,int minv,int maxv){
         if(!root)return true;

         if(root->val <= minv && root->val >= maxv)return false;

         return valid(root->left,minv,root->val) && valid(root->right,root->val,maxv);
    }

    bool isValidBST(TreeNode* root) {
        int minv=INT_MIN,maxv=INT_MAX;
        return validate(root,minv,maxv);
    }
};