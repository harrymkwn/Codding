#ifndef UNTITLED_SEGMENTTREE
#define UNTITLED_SEGMENTTREE
#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<int> arr, tree;

public:
    SegmentTree(vector<int> data);
    void buildtree(int start, int end, int in);
    void update(int start, int end, int in, int ind, int val);
    int query(int start, int end, int l, int r, int in);
    void print();
};


#endif