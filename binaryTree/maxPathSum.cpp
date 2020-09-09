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

int maxPathSumHelper(BinaryTree* tree,int &sum){

    if(tree->left==NULL &&tree->right==NULL){
        return tree->value;
    }
    int left =0,right =0;
    if(tree->left!=NULL)left = maxPathSumHelper(tree->left,sum);
    if(tree->right!=NULL)right = maxPathSumHelper(tree->right,sum);
	if(sum > left + right + tree->value)sum = left + right + tree->value;
        cout<<tree->value<<" "<<left<<" "<<right<<"\n";
    return max(left,right) + tree->value;
}

int maxPathSum(BinaryTree tree) {
    int sum=0;
  maxPathSumHelper(&tree,sum);
}