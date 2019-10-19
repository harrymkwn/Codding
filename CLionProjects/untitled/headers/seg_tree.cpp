//
// Created by harry on 23/6/19.
//

#include "seg_tree.h"
#include <bits/stdc++.h>
using namespace std;

void seg_tree::update(int * arr,int * tree , int start,int end,int in, int idx, int val) {

    if (start == end) {
        arr[idx] = val;
        tree[in] = val;
        return;
    } else {
        int mid = (start + end) >> 1;
        if (mid >= idx && idx >= start) {
            update(arr, tree, start, mid, 2 * in, idx, val);
        } else {
            update(arr, tree, mid + 1, end, (2 * in) + 1, idx, val);
        }
        tree[in] = tree[2 * in] + tree[2 * in + 1];
    }
}


void seg_tree::buildtree(int* arr,int *tree,int start,int end,int in){

    if(start==end){
        tree[in]=arr[start];
        return;
    } else{
        int mid = (start+end)>>1;
        buildtree(arr,tree,start,mid,2*in);
        buildtree(arr,tree,mid+1,end,2*in+1);
        tree[in] = tree[2*in] + tree[2*in + 1];
    }
}

void seg_tree::print(int* tree,int n){
    int twos =1;
    for(int i=1;i<n;i++) {
        if (twos ==i) {
            cout << "\n";
            twos*=2;
        }
        if(tree[i])
            cout << tree[i] << " ";
    }
}

int seg_tree::query(int * tree,int in,int start,int end,int l,int r){
    if(start>r || end<l){
        return  0;
    }
    if(start>=l && end<=r){
        return tree[in];
    }
    int mid = (start + end)/2;
    int q1=query(tree,2*in,start,mid,l,r);
    int q2=query(tree,(2*in)+1,mid+1,end,l,r);
    return q1+q2;
}

seg_tree::seg_tree(int n) {

    arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int h =(int)(ceil(log2(n)));
    int size  =  2 *(int)pow(2,h) - 1;
    int * tree = new int[size];
    for(int i=0;i<size;i++)tree[i]=0;

    delete[](arr);
    delete [] tree;
}