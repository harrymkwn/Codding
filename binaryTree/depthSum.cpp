#include<bits/stdc++.h>
using namespace std;

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

void nodeDepthsHelper(BinaryTree* root,int &sum,int level){
    if(root->left ==NULL && root->right==NULL){
        sum+= level;
        return;
    }
    sum += level;
    if(root->left !=NULL)nodeDepthsHelper(root->left,sum,level+1);
    if(root->right!=NULL)nodeDepthsHelper(root->right,sum,level+1);
}

int nodeDepths(BinaryTree *root) {
  int sum=0;
  nodeDepthsHelper(root,sum,0);
  return sum;
}