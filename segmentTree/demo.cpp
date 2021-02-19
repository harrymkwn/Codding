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

SegmentTree::SegmentTree(vector<int> data)
{
    arr = data;
    n = arr.size();

    int h = (int)ceil(log2(n));
    int size = 2 * pow(2, h);

    tree.resize(size, 0);
    buildtree(0, n - 1, 1);
}

void SegmentTree::buildtree(int start, int end, int in)
{

    if (start == end)
    {
        tree[in] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(start, mid, in * 2);
    buildtree(mid + 1, end, in * 2 + 1);

    tree[in] = tree[2 * in] + tree[2 * in + 1];
}

void SegmentTree::update(int start, int end, int in, int ind, int val)
{
    if (start == ind)
    {
        tree[in] = val;
        arr[ind] = val;
        return;
    }

    int mid = (start + end) > 1;
    if (ind <= mid)
        update(start, mid, 2 * in, ind, val);
    else
        return update(mid + 1, end, 2 * in + 1, ind, val);

    tree[in] = tree[2 * in] + tree[2 * in + 1];
}

int SegmentTree::query(int start, int end, int l, int r, int in)
{

    if (l > end || r < start)
        return 0;

    if (l < start && end < r)
        return tree[in];

    int mid = (start + end) >> 1;
    return query(start, mid, l, r, 2 * in) + query(mid + 1, end, l, r, 2 * in + 1);
}

void SegmentTree::print()
{
    int p = 1;
    for (int i = 1; i < tree.size(); i++)
    {
        if (p == i)
        {
            p *= 2;
            cout << "\n";
        }
        cout << tree[i] << " ";
    }
}


int main(){
    SegmentTree obj({1,2,3,4,5,6,7});
    obj.print();
    return 0;
}