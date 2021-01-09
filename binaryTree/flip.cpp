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
    bool isSameTreeModefied(TreeNode* p, TreeNode* q) {
     if(!p && !q)return true;
     else if(!p || !q)return false;
     else return ((p->val == q->val) && (isSameTreeModefied(p->left,q->right)||isSameTreeModefied(p->left,q->left)) && (isSameTreeModefied(p->right,q->left)||isSameTreeModefied(p->right,q->right))); 
    }
public:a
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return isSameTreeModefied(root1,root2);
    }
};