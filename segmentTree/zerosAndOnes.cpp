#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> tree;

void buildtree(int start, int end, int in)
{

    if (start == end)
    {
        tree[in] = 1;
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(start, mid, in * 2);
    buildtree(mid + 1, end, in * 2 + 1);

    tree[in] = tree[2 * in] + tree[2 * in + 1];
}

void updateUtils(int start, int end, int in, int ind, int val)
{
    if (start == ind)
    {
        tree[in] = 0;
        return;
    }

    int mid = (start + end) > 1;
    if (ind <= mid)
        updateUtils(start, mid, 2 * in, ind, val);
    else
        updateUtils(mid + 1, end, 2 * in + 1, ind, val);

    tree[in] = tree[2 * in] + tree[2 * in + 1];
}

int queryUtils(int start, int end, int in,int k )
{
    if(start < 0 || end >= n || tree[in] < k)return -1;

    if(start==end && k==1)return start;

    int mid = (start + end) >> 1;
    int left = 2*in;
    int right = 2*in+1;
    if(k > tree[left])
        return queryUtils(mid+1,end,right,k-tree[left]);
    else return queryUtils(start,mid,left,k);    
}


void update(int ind){
    return updateUtils(0, n - 1, 1, ind, 0);
}

int query(int kth){
    if(tree[1]<kth)return 1;

    int temp = queryUtils(0,n-1,1,kth);

    return temp;

}


int main()
{
    int  t;
    cin >> n;
    int h = (int)ceil(log2(n));
    int size = 2 * pow(2, h);

    tree.resize(size, 0);
    buildtree(0, n - 1, 1);

    // obj.print();

    cin >> t;
    int x, y;
    while (t--)
    {
        cin >> x >> y;
        if (x == 0)
            update(y-1);
        else cout<<query(y)+1<<"\n";
    }

    // obj.print();

    return 0;
}