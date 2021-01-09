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
    
    void findMode(TreeNode* root,unordered_map<int,int> &mp){
        if(!root)return;
        mp[root->val]++;
        if(root->left)findMode(root->left,mp);
        if(root->right)findMode(root->right,mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        unordered_map<int,int> mp;
        findMode(root,mp);

        int max=0;
        for(auto x:mp){
            if(x.second>max){ret.clear();ret.push_back(x.first);}
            else if(x.second==max){ret.push_back(x.first);}
        }

        return ret;
    }
};