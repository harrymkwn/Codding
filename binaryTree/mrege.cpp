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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* temp = new TreeNode();
        if(!t1 && !t2)return NULL;
        else if(!t1 || !t2){
            if(t1)temp = t1;
            else temp = t2;
        }
        else{
            temp->left = mergeTrees(t1->left,t2->left);
            temp->right = mergeTrees(t1->right,t2->right);
            temp->val = t1->val  + t2->val;
        }
        return temp;
    }
};