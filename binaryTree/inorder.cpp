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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode* > s;
        unordered_map<TreeNode* ,int> mp;
        TreeNode* temp = root;
        s.push(temp);

        while(!s.empty()){
            temp = s.top();
            if(!temp){s.pop();continue;}
            if(mp[temp]==0)s.push(temp->left);
            else if(mp[temp]==1) ret.push_back(temp->val);
            else if(mp[temp]==2) s.push(temp->right);
            else {s.pop();continue;}
            mp[temp]++;
        }

        return ret;
    }
};