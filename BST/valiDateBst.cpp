#include <bits/stdc++.h>
using namespace std;

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

bool validateBst(BST *tree)
{
    return validateBSTHelper(tree,INT_MAX,INT_MIN);
}

bool validateBSTHelper(BST *tree, int maxValue, int minValue)
{
    if (!tree->left && !tree->right)
        return true;
    if (tree->right == NULL && tree->left != NULL)
        if (tree->value > tree->left->value)
            return validateBst(tree->left);
        else
            return false;
    if (tree->left == NULL && tree->right != NULL)
        if (tree->value < tree->right->value)
            return validateBst(tree->right);
        else
            return false;
    if (tree->value > tree->left->value && tree->right->value > tree->value)
        return validateBst(tree->left) && validateBst(tree->right);
    return false;
}