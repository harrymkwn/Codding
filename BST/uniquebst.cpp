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

    void generateTree(vector<int> a,vector<TreeNode*> &ret){
        if(a.size()==1)return ret.push_back(new TreeNode(a[0]));

        for(int i=0;i<a.size();i++){
            vector<int> arr1(a.begin(),a.begin()+i-1);
            vector<int> arr2(a.begin()+i+1,a.end());
            TreeNode* temp = new TreeNode(a[i])
            temp->left =     generateTree(arr1,ret);
            generateTree(arr2,ret);
        }

        
    }
public:
    vector<TreeNode*> generateTrees(int n) {

        vector<int> a(n,0);
        for(int i=0;i<n;i++)a[i]=i+1;
        vector<TreeNode*> ret;

        generateTree(a,ret);
    }
};