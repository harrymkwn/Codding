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
    int maxv=0;
public:
    int lUP(TreeNode* root) {
        if(!root->left && !root->right)return 0;

        int left = 0,right=0;
        if(root->left)left = lUP(root->left);
        if(root->right)right = lUP(root->right);

        if(root->left && root->right && root->val==root->left->val &&root->val==root->right->val){
            ;
        }else if((root->left && root->val==root->left->val)){
            right = -1;
        }
        else if(root->right && root->val==root->right->val){
            left = -1;
        }else {
            left = -1,right=-1;
        }
        int cur = left + right + 2;
        if(cur>maxv)maxv=cur;
        return max(left,right)+1;
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root)return true;
        lUP(root);
        return maxv;
    }
};