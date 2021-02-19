#include <bits/stdc++.h>
using namespace std;
//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void verticalTraversal(TreeNode *root, map<int, vector<int>> &mp, int dist)
    {
        if (!root)
            return;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        // mp[dist].push_back(root->val);
        pair<TreeNode *, int> temp;
        while (!q.empty())
        {
            int n = q.size();
            set<pair<int,int>> s;
            while (n--)
            {
                temp = q.front();
                q.pop();

                s.insert({temp.second,temp.first->val});


                if (temp.first->left)
                    q.push({temp.first->left, temp.second - 1});
                if (temp.first->right)
                    q.push({temp.first->right, temp.second + 1});
            }
            for(auto x: s)
                mp[x.first].push_back(x.second);
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<int>> mp;
        vector<vector<int>> ret;
        if (!root)
            return ret;

        verticalTraversal(root, mp, 0);
        ret.resize(mp.size());
        int i = 0;
        for (auto x : mp)
        {
            ret[i++] = x.second;
        }
        return ret;
    }
};