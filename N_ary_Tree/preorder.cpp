#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {

    void preorder(Node* root,vector<int> &ret){
        if(!root)return;

        ret.push_back(root->val);

        for(auto x : root->children){
            preorder(x);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if(!root)return ret;

        preorder(root,ret);
    }
};