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
    int maxh=0;
    void height(TreeNode* root,int h){
        if(!root)return ;
        if(maxh>h)maxh=h;
        if(root->left)height(root->left,h+1);
        if(root->right)height(root->right,h+1);
    }
public:
    int maxDepth(TreeNode* root) {
        height(root,1);
        return maxh;
    }
};