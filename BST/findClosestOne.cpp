#include<bits/stdc++.h>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  
	if(tree == NULL)return -1;
    int left=INT_MAX,right=INT_MAX;
    if(tree->left != NULL)left = findClosestValueInBst(tree->left,target);
    if(tree->right != NULL)right = findClosestValueInBst(tree->right,target);
	
  return min(abs(target - tree->value),0 );
}
