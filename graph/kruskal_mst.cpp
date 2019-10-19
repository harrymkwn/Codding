#include <bits/stdc++.h>
using namespace std;
struct node
{
    int s, d, val;
    node() : s(0), d(0), val(0){};
};

bool check(node a, node b)
{
    if (a.val != b.val)
        return a.val < b.val;
    else if (a.d != b.d)
        return a.d < b.d;
    return a.s < b.s;
}
int find(int *parent, int point)
{
    while (parent[point] != point)
        point = parent[point];

    return point;
}

void kruskal(node *arr, int n, int e)
{
    node *mst = new node[n];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int count = 0;
    int v = 0;
    while (count < n - 1)
    {
        int ps = find(parent, arr[v].s);
        int pd = find(parent, arr[v].d);
        if (ps != pd)
        {
            mst[count] = arr[v];
            count++;
            parent[ps] = pd;
        }
        v++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (mst[i].s < mst[i].d)
            cout << mst[i].s << " " << mst[i].d << " " << mst[i].val << "\n";
        else
            cout << mst[i].d << " " << mst[i].s << " " << mst[i].val << "\n";
    }
    delete[] mst;
}
int main()
{
    int n, e;
    cin >> n >> e;
    node *arr = new node[e];
    for (int i = 0; i < e; i++)
        cin >> arr[i].s >> arr[i].d >> arr[i].val;

    sort(arr, arr + e, check);

    kruskal(arr, n, e);

    delete[] arr;
}