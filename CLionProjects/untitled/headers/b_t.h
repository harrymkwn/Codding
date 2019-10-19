//
// Created by harry on 20/6/19.
//

#ifndef UNTITLED_B_T_H
#define UNTITLED_B_T_H


//
//struct node* root  = bt.newNode(1);
//root->left =bt.newNode(2);
//root->right=bt.newNode(3);
//root->left->left=bt.newNode(4);
//root->left->right=bt.newNode(5);
//root->right->left=bt.newNode(6);
//root->right->right=bt.newNode(7);
//
//bt.dfs(root);
//cout<<"\n";
//bt.bfs(root);
//
//









struct  node{
    int data;
    struct node* left;
    struct node* right;
};



class b_t {


public:
    struct node* newNode(int k);
    void dfs(node* root);
    void bfs(node* root);
};


#endif //UNTITLED_B_T_H
