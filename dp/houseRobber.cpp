#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {

    map<TreeNode*,pair<int,int>> mp;

    void robUtils(TreeNode* root){
        if(!root)return;

        int sum1{0},sum2{0};

        if(root->left){
            robUtils(root->left);
            sum1 += mp[root->left].second;
            sum2 += max(mp[root->left].second , mp[root->left].first);
        }
        if(root->right){
            robUtils(root->right);
            sum1 += mp[root->right].second;
            sum2 += max(mp[root->right].second , mp[root->right].first);
        }
        mp[root] = {sum1+root->val,sum2};
    }


public:
    int rob(TreeNode* root) {
        if(!root)return 0;

        robUtils(root);
        return max(mp[root].first,mp[root].second);
    }
};


int main(){
    
    return 0;
}