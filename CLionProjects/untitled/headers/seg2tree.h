//
// Created by harry on 24/6/19.
//

#ifndef UNTITLED_SEG2TREE_H
#define UNTITLED_SEG2TREE_H



struct node{
    long long ms,sum,bps,bss;
};

class seg2tree {


public:

    seg2tree();
    void seg_tree(int* arr, node*tree ,int start,int end,int in);
    node query(node* tree , int start,int end,int l,int r,int in);
    long long tot_max(long long a,long long b,long long c,long long d,long long e);
};


#endif //UNTITLED_SEG2TREE_H
