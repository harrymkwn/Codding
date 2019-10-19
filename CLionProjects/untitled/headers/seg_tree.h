//
// Created by harry on 23/6/19.
//

#ifndef UNTITLED_SEG_TREE_H
#define UNTITLED_SEG_TREE_H


class seg_tree {

private:
    int *arr;

public:
    seg_tree(int n);
    void update(int * arr,int * tree , int start,int end,int in, int idx, int val);
    void buildtree(int* arr,int *tree,int start,int end,int in);
    int query(int * tree,int in,int start,int end,int l,int r);
    void print(int* tree,int n);
};


#endif //UNTITLED_SEG_TREE_H
