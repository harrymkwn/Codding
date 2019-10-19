//using struct

//there is defect in program
#include <bits/stdc++.h>
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

int kthsm(node *root, int k)
{
    node *curr = root;
    int ksmall = 0;
    int count = 0;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            count++;
            if (count == k)
                ksmall = curr->data;

            curr = curr->right;
        }
        else
        {
            node *pre = curr->left;

            while (pre->right != NULL && pre->right != curr)    
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                count++;

                if (count == k)
                    ksmall = curr->data;

                curr = curr->right;
            }
        }
    }
    return ksmall;
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

    int k;
    cin >> k;
    cout << kthsm(root, k);
}
