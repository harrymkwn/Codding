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
    int mindepth=INT_MAX;
    
    void minDepth(TreeNode* root,int level){
        if(!root->left && !root->right) {mindepth = (mindepth>level) ? level : mindepth;return;}

        if(root->left)minDepth(root->left,level+1);
        if(root->right)minDepth(root->right,level+1);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        minDepth(root,1);
        return mindepth==INT_MAX ? 0 : mindepth;
    }
};