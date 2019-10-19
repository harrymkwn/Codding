#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int val = 0) : data(val), left(NULL), right(NULL) {}
};

void inorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

node *insert(node *root, int val)
{
    if (root == NULL)
        return new node(val);

    if (root->data > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

bool isbst(node* root,int min,int max){
    if(root==NULL)return true;

    if(root->data<min || root->data>max)return false;

    return isbst(root->left,min,root->data-1) && isbst(root->right,root->data+1,max);
}

int main()
{
    node *root = new node(12);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 14);
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 50);

    if(isbst(root,INT_MIN,INT_MAX))
        cout<<"tree is bst";
    else
        cout<<"tree is not bst";
    inorder(root);
}