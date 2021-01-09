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
    int maxv=0;

    void depth(Node* root,int h){
        if(!root)return;
        if(h>maxv)maxv=h;

        for(auto x : root->children){
            depth(x,h+1);
        }

    }
public:
    int maxDepth(Node* root) {
        if(!root)return 0;
        depth(root,maxv);
        return maxv;
        
    }
};