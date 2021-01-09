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

// class Solution {
//     int maxh=0;
//     vector<bool> isThere;

//     void height(TreeNode* root,int h){
//         if(!root)return ;
//         if(maxh>h)maxh=h;
//         if(root->left)height(root->left,h+1);
//         if(root->right)height(root->right,h+1);
//     }
//     bool isCompleteTree(TreeNode*root, int l){
//         if(!root){this->isThere[l]=false;return true;}
//         if(!this->isThere[l])return false;
//         if(this->isThere[l]){
//             for(int i=0;i<this->isThere.size();i++){
//                 if(this->isThere[l])return false;
//             }
//         }
//         return isCompleteTree(root->left,l+1) && isCompleteTree(root->right,l+1);
//     }
// public:
//     bool isCompleteTree(TreeNode* root) {
//         height(root,1);
//         isThere.resize(maxh+1,true);
//         return isCompleteTree(root,0);
//     }
// };

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
           int n = q.size();

           while(n--){
               bool f=false;
               TreeNode* temp = q.front();
               q.pop();
                if(!temp){
                    f = false;
                }else if(temp && f)return false;
                else{
                    q.push(root->left);
                    q.push(root->right);
                }
           }
       }
       return true;
    }
};