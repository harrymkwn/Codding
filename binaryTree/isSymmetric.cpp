
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
    bool isSymmetric(TreeNode* p,TreeNode* q){
     if(!p && !q)return true;
     else if(!p || !q)return false;
     else (p->val == q->val) && this->isSymmetric(p->left,q->right) && this->isSymmetric(p->right,q->left);
    }
public:

    bool isSymmetric(TreeNode* root) {
        if(!root || (root && !root->left && !root->right))return true;
        else if(!root->left || !root->right)return false;
        return this->isSymmetric(root->left,root->right); 
    }
};