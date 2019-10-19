#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left, * right;
    int height;
    node(int k,int h): data(k),left(NULL),right(NULL),height(h){}
};

void inorder(node* root){

    if(root==NULL)return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* change(node* root){

    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root=temp;
    return root;
}
int getheight(node* root){

    if(root==NULL)return 0;

    return root->height;

}

int getbalanced(node* root){

    if(root==NULL)return 0;

    return getheight(root->left)- getheight(root->right) ;
}


node* rightRotate(node* root){

    node* x = root->left;
    node* temp = root->right;

    x->right = root;
    root->left = temp;

    root->height = 1 + max(getheight(root->left) , getheight(root->right));
    x->height = 1 + max(getheight(x->left) , getheight(x->right));

    return x;
}

node* leftRotate(node* root){

    node* x = root->right;
    node* temp = root->left;

    x->left = root;
    root->right = temp;

    root->height = 1 + max(getheight(root->left) , getheight(root->right));
    x->height = 1 + max(getheight(x->left) ,getheight(x->right));

    return x;
}


node* insert(node* root,int key){
    if(root==NULL)return new node(key ,1);

    if(key > root->data)
        root->right = insert(root->right,key);
    else if(key < root->data)
        root->left = insert(root->left,key);
    else return root;

    root->height = 1 + max(getheight(root->left),getheight(root->right));

    int balance  = getbalanced(root);

    if(balance>1 && key < root->left->data)
        return rightRotate(root);

    if(balance < -1 && key > root->right->data)
        return leftRotate(root);

    if(balance>1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
int main(){

    node* root = new node(5,1);

    root = insert(root,3);
    root = insert(root,2);
    root =insert(root,1);
    root = insert(root,4);

    inorder(root);
    cout<<"\n"<<root->data<<"\n";
}