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
    bool flag=false;
    
    void hasPathSum(TreeNode* root,int sum,int until){
        if(!root->left && !root->right){flag = ((until+root->val)== sum) ? true : false;return;}

        if(root->left)hasPathSum(root->left,sum,until+root->val);
        if(root->right)hasPathSum(root->right,sum,until+root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        hasPathSum(root,sum,0);
        return flag;
    }
};