//
// Created by harry on 20/6/19.
//

#include "b_t.h"
#include <bits/stdc++.h>
using namespace std;

struct node* b_t::newNode(int k) {
    struct node* node = new struct node;
    node->data = k;
    node->left = NULL;
    node->right = NULL;

    return node;
}


void b_t::dfs(struct  node *root) {

    if(root==NULL)
        return ;

    cout<<root->data<<" ";
    dfs(root->left);
    dfs(root->right);
}

void b_t::bfs(struct  node *root) {

    queue<struct node*>q;

    q.push(root);

    while (!q.empty()){
        struct node* top = q.front();
        q.pop();
        cout<<top->data<<" ";
        if(top->left!=NULL)
            q.push(top->left);
        if(top->right!=NULL)
            q.push(top->right);
    }

}