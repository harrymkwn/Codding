//using struct
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int val=0) : data(val),left(NULL),right(NULL) {}
};

// bool inorder(node *root, vector<int>&arr)
// {
//     if (root != NULL)
//     {
//         inorder(root->left,arr);
//         arr.push_back(root->data);
//         inorder(root->right,arr);
//     }
// }
void find(node *root,int&k){
    if(root==NULL || k>=5)return;

    find(root->left,k);
    k++;
    if(k==5){
        cout<<"5th largest integer is : "<<root->data<<"\n";
        return;
    }
    find(root->right,k);
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

int main()
{
    node *root = new node(20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 7);
    root = insert(root, 50);
    //static int k = 5;
    //vector<int>smallest;
    // inorder(root,smallest);
    // //for(int i=0;i<smallest.size();i++)
    //     cout<<smallest[k-1];
    int k=0;
    find(root,k);
}