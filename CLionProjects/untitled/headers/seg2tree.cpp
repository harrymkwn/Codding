//
// Created by harry on 24/6/19.
//

#include "seg2tree.h"
#include<bits/stdc++.h>
using  namespace std;


long long seg2tree::tot_max(long long a,long long b,long long c,long long d,long long e){
    return max(a,max(b,max(c,max(d,e))));
}



void seg2tree::seg_tree(int* arr, node*tree ,int start,int end,int in){
    if(start == end){
        tree[in].ms = arr[start];
        tree[in].sum = arr[start];
        tree[in].bps = arr[start];
        tree[in].bss = arr[start];
        return ;
    }
    int mid = (start+end)/2;
    seg_tree(arr,tree,start,mid,2*in);
    seg_tree(arr,tree,mid+1,end,2*in+1);
    node l = tree[2*in];
    node r = tree[2*in +1];
    tree[in].ms = tot_max(l.ms,r.ms,l.sum+r.bps,r.sum+l.bss,r.bps+l.bss);
    tree[in].sum = r.sum+l.sum;
    tree[in].bps = max(l.bps,l.sum+r.bps);
    tree[in].bss = max(r.bss,r.sum+l.bss);
    return;
}




node seg2tree::query(node* tree , int start,int end,int l,int r,int in){
    if(start>r || end <l)
    {
        node b;
        b.ms=0,b.sum=0,b.bps=0,b.bss=0;
        return b;
    } else if(start>=l && end<=r)
    {
        return tree[in];
    }else {
        int mid = (start+end)/2;
        node ls = query(tree,start,mid,l,r,2*in);
        node rs = query(tree,mid+1,end,l,r,2*in+1);
        node a;
        a.ms = tot_max(ls.ms,rs.ms,ls.sum+rs.bps,rs.sum+ls.bss,rs.bps+ls.bss);
        a.sum = rs.sum+ls.sum;
        a.bps = max(ls.bps,ls.sum+rs.bps);
        a.bss = max(rs.bss,rs.sum+ls.bss);
        return a;
    }
}

seg2tree::seg2tree() {
    int n,m;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int * arr = new int[n];
    int h = (int)ceil(log2(n));
    long long size = 2*pow(2,h) ;
    node * tree = new node[size];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    for(int i =0;i<size;i++)
        tree[i].ms=0,tree[i].sum=0,tree[i].bps=0,tree[i].bss=0;
    cin>>m;
    seg_tree(arr,tree,0,n-1,1);
    while(m--){
        int y,z;
        cin>>y>>z;
        node a = query(tree,0,n-1,y-1,z-1,1);
        cout<<a.ms<<"\n";
    }
    delete[] arr;
    delete[] tree;
}