#include<bits/stdc++.h>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};


void branchSumsHelper(BinaryTree* root,vector<int> &ret, int sum){
    if(root->left == NULL && root->right ==NULL){
        ret.push_back(sum+root->value);
        return;
    }
    if(root->left != NULL)branchSumsHelper(root->left,ret,sum+root->value);
    if(root->right != NULL)branchSumsHelper(root->right,ret,sum+root->value);
}

vector<int> branchSums(BinaryTree *root) {
  vector<int> ret;
	branchSumsHelper(root,ret,0);
  return ret;
}
