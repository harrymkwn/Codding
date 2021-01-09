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
    bool flag=true;
    int isBalanced(TreeNode* root,int f){
    if(this->flag){
        if(!root)return 0;
        int left=0,right = 0;
        if(root->left)left = isBalanced(root->left,f);
        if(root->right)right = isBalanced(root->right,f);

        if(abs(left-right)>1){flag = false; return 0;}
        else return max(left,right)+1;
    }
    return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        isBalanced(root,0);
        return this->flag;
    }
};