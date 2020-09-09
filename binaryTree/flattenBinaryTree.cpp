#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};

BinaryTree *flattenBinaryTreeHelper(BinaryTree *curentNode,BinaryTree* parentNode){
    if(curentNode->left==NULL && curentNode->right == NULL){
        curentNode->right = parentNode;
        retun curentNode;
    }    
}

BinaryTree *flattenBinaryTree(BinaryTree *root){
  return root;
}
