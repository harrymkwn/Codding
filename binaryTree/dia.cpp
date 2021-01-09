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
    int ans=0;

    int diameterTree(TreeNode* root){
        if(!root)return 0;
        int L = diameterTree(root->left);
        int R = diameterTree(root->right);
        ans = max(ans,L+R+1);
        return max(L,R)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        diameterTree(root);
        return ans-1;
    }
};