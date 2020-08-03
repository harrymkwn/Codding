#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

void maxPathSumHelper(BinaryTree* tree,int &firstLarge,int &secondLarge,int cur){

    if(tree->left==NULL &&tree->right==NULL){
        if(cur+tree->value > sum) sum = cur + tree->value;
        return;
    }
    if(tree->left!=NULL)maxPathSumHelper(tree->left,firstLarge,secondLarge,cur+tree->value);
    if(tree->right!=NULL)maxPathSumHelper(tree->right,firstLarge,secondLarge,cur+tree->value);
}

int maxPathSum(BinaryTree tree) {
  int firstLarge=0,secondLarge=0;
  maxPathSumHelper(&tree,firstLarge,secondLarge,0);
  return sum;
  
}