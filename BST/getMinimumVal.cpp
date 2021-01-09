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
    void getMinimumDifference(TreeNode* root,int minv,int maxv,int &mind){
        if(!root)return ;

        int x = abs(root->val - minv);
        mind = mind > x ? x : mind;
        x = abs(root->val - maxv);
        mind = mind > x ? x : mind;

        if(root->left){
            int x = abs(root->val - root->left->val);
            mind = mind > x ? x : mind;

            getMinimumDifference(root->left,minv,root->val,mind);
        }
        if(root->right){
            int x = abs(root->val - root->right->val);
            mind = mind > x ? x : mind;
            getMinimumDifference(root->right,minv,root->val,mind);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mind=INT_MAX;
        getMinimumDifference(root,INT_MIN,INT_MAX,mind);
        return mind;
    }
};