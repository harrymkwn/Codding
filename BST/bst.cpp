//using struct
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

node *search(node *root, int key, int level)
{
    if (root->data == key)
    {
        cout << level << " ";
        return root;
    }
    if (root->data > key)
        return search(root->left, key, level + 1);

    return search(root->right, key, level + 1);
}
node *findmin(node *root)
{
    if (root == NULL)
        return root;
    else if (root->left == NULL)
        return root;
    else
        return findmin(root->left);
}

node *findmax(node *root)
{
    if (root == NULL)
        return root;
    else if (root->right == NULL)
        return root;
    else
        return findmin(root->right);
}

node *remove(node *root, int val)
{
    if (root == NULL)
        return NULL;
    else if (root->data < val)
        root->right = remove(root->right, val);
    else if (root->data > val)
        root->left = remove(root->left, val);
    else if (root->left && root->right)
    {
        node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, root->data);
    }
    else
    {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
    }
    return root;
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

    inorder(root);
    node *serchednode = search(root, 15, 0);
    cout << serchednode->data;

    cout << "\n";
    root = remove(root, 15);
    inorder(root);
}