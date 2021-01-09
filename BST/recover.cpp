
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
    TreeNode *n1,*n2;
    public:

    void inorder(TreeNode* cur,TreeNode* prev){
        if(!cur)return;

        inorder(cur->left,prev);

        if(prev > cur){
            if(n1){
                n2=cur;
            }
            else {
                n1 = prev;
                n2 = cur;
            }
        }
        prev = cur;
        inorder(cur->right,prev);
    }

    void recoverTree(TreeNode* root) {
        this->n1=nullptr;
        this->n2=nullptr;
        this->inorder(root,nullptr);

        int cache = n1->val;
        n1->val = n2->val;
        n2->val = cache;
    }
};