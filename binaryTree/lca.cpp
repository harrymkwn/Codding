#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    TreeNode* ret;

    bool lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)return false;

        bool left=false,right=false,cur=false;
        if(root->left)left = lca(root->left,p,q);
        if(root==p || root==q)cur = true;
        if(root->right)right = lca(root->right,p,q);

        if(left&&right || cur&&right || cur&&left){this->ret = root; return false;}
        if(left || right || cur)return true;
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->ret = nullptr;
        this->lca(root,p,q);
        return ret;
    }
};