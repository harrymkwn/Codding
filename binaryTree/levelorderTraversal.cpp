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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if(!root)return ret;
    queue<pair<TreeNode* ,int>> q;
    q.push({root,0});

    while(!q.empty()){
        pair<TreeNode*,int> temp = q.front();
        q.pop();
        try
        {
            ret.at(temp.second).push_back(temp.first->val);
        }
        catch(const std::exception& e)
        {
            ret.push_back({temp.first->val});
        }

        if(temp.first->left)q.push({temp.first->left,temp.second+1});
        if(temp.first->right)q.push({temp.first->right,temp.second+1});
    }
    reverse(ret.begin(),ret.end());

    return ret;
    }
};