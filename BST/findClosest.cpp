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
void findClosestValueInBstHelper(BST* tree, int target, int &minDiff, int &value) {
    if (tree->left == NULL && tree->right == NULL)return ;
    if (abs(target - tree->value)< minDiff){
        minDiff = abs(target - tree->value);
        value = tree->value;
    }
    if (tree->left != NULL)findClosestValueInBstHelper(tree->left, target, minDiff, value);
    if (tree->right != NULL)findClosestValueInBstHelper(tree->right, target, minDiff, value);
    return;
}
int findClosestValueInBst(BST *tree, int target) {
    int minDiff = INT_MAX, value = 0;
    findClosestValueInBstHelper(tree, target, minDiff, value);
    return minDiff == INT_MAX ? -1 : value;
}