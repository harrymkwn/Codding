#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

void build_tree(vector<int> &tree, vector<int> arr, int start, int end, int in)
{
    if (start == end)
    {
        tree[in] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    build_tree(tree, arr, start, mid, 2 * in);
    build_tree(tree, arr, mid + 1, end, 2 * in + 1);

    tree[in] = tree[2 * in] + tree[2 * in + 1];
}
void update(vector<int> &tree, vector<int> &arr, int start, int end, int in, int ind, int val)
{

    if (start == ind)
    {
        tree[in] = val;
        arr[ind] = val;
        return;
    }
    int mid = (start + end) >> 1;
    if (ind <= mid)
        update(tree, arr, start, mid, 2 * in, ind, val);
    else
        update(tree, arr, mid + 1, end, 2 * in + 1, ind, val);

    tree[in] = tree[2 * in] + tree[2 * in + 1];
}
int query(vector<int> tree, vector<int> arr, int start, int end, int in, int l, int r)
{

    if (l > end || r < start)
        return 0;
    if (start >= l && end <= r)
        return tree[in];

    int mid = (start, end) >> 1;

    return query(tree, arr, start, mid, 2 * in, l, r) + query(tree, arr, mid + 1, end, 2 * in + 1, l, r);
}

void print_tree(vector<int> tree)
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

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    F(0, n, i)
    cin >> arr[i];

    int h = (int)ceil(log2(n));
    int size = 2 * pow(2, h);
    vector<int> tree(size, 0);

    build_tree(tree,arr,0,n-1,1);
    cout<<query(tree,arr,0,n-1,1,2,4);
    return 0;
}