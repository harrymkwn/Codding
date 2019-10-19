#include <iostream>
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

node *find(node *root, int val1, int val2)
{
    if (root == NULL)
        return NULL;

    if (root->data > val1 && root->data > val2)
        return find(root->left, val1, val2);

    if (root->data < val1 && val2 > root->data)
        return find(root->right, val1, val2);

    return root;
}

//Iterative methods
// node *lca(node *root, int n1, int n2)
// {
//     while (root != NULL)
//     {
//         if (root->data > n1 && root->data > n2)
//             root = root->left;
//         else if (root->data < n1 && root->data < n2)
//             root = root->right;

//         else
//             break;
//     }
//     return root;
// }

int main()
{
    node *root = new node(20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    inorder(root);
    int x = -5, y = -5;
    while ((cin >> x >> y) && x > -1 && y > -1)
    {
        node *temp = find(root, x, y);
        cout << temp->data << "\n";
    }

    return 0;
}