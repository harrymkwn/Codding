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

    vector<TreeNode*> generateTrees(int s,int e){

        vector<TreeNode*> ret;
        if(s>e){ret.push_back(nullptr);return;}

        for(int i=s;i<=e;i++){
            vector<TreeNode*> lt = generateTrees(0,i-1);
            vector<TreeNode*> rt = generateTrees(i+1,e);

            for(auto ltree : lt){
                for(auto rtree : rt){
                    TreeNode* node = new TreeNode(i);
                    node->left = ltree;
                    node->right = rtree;
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
public:

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(0,n-1);
    }
};


int main(){
    
    return 0;
}