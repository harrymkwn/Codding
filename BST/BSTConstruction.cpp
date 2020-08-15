#include <vector>
using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST &insert(int val) {
        if (val < value) {
            if (left == NULL) {
                BST* newbst = new BST(val);
                left = newbst;
            }
            else
            {
                left->insert(val);
            }
        }
        else
        {
            if (right == NULL) {
                BST* newbst = new BST(val);
                right = newbst;
            }
            else
            {
                right->insert(val);
            }
        }
        return *this;
    }

    bool contains(int val) {
        if (val < value) {
            if (left==NULL) {
                return false;
            }
            return left->contains(val);
        }
        else if (val>value) {
            if (right==NULL) {
                return false;
            }
            return right->contains(val);
        }
        else {
            return true;
        }
    }

    BST &remove(int val, BST* parent = NULL) {
        if (val < value) {
            if (left != NULL)left->remove(val, this);
        }
        else if (val > value) {
            if (right!=NULL)right->remove(val, this);
        }
        else {
            if (left !=NULL && right !=NULL) {
                value = right->getMinimum();
                right->remove(value, this);
            }
            else if (parent == NULL)
            {
                if (left !=NULL) {
                    value = left->value;
                    right = left->right;
                    left = left->left;
                }
                else if (right != NULL) {
                    value = right->value;
                    left = right->left;
                    right = right->right;
                }
                else
                {

                }

            }
            else if (parent->left ==this)
            {
                parent->left = left!=NULL ? left : right;
            }
            else if (parent->right == this)
            {
                parent->right = left != NULL ?left : right;
            }
        }
        return *this;
    }

    int getMinimum() {
        if (left==NULL)return value;
        else return left->getMinimum();
    }
};
