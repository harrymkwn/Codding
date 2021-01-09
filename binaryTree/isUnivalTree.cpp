
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
    bool isunivaluedTree(TreeNode* root,int val){
        if(!root)return true;
        if(root->val!=val)return false;

        return isunivaluedTree(root->left,val) && isunivaluedTree(root->right,val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        return isunivaluedTree(root,root->val);
    }
};