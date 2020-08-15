#include <vector>
using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
};

vector<int> inOrderTraverse(BST *tree, vector<int> array) {

    if (tree->left != NULL)
        array = inOrderTraverse(tree->left, array);

    array.push_back(tree->value);

    if (tree->right != NULL)
        array = inOrderTraverse(tree->right, array);

    return array;
}

vector<int> preOrderTraverse(BST *tree, vector<int> array) {

    array.push_back(tree->value);

    if (tree->left != NULL)
        array = inOrderTraverse(tree->left, array);

    if (tree->right != NULL)
        array = inOrderTraverse(tree->right, array);

    return array;
}

vector<int> postOrderTraverse(BST *tree, vector<int> array) {

    if (tree->left != NULL)
        array = inOrderTraverse(tree->left, array);

    if (tree->right != NULL)
        array = inOrderTraverse(tree->right, array);

    array.push_back(tree->value);

    return array;
}
