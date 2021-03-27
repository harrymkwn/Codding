#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<int> arr,tree;

    void buildtree(int start, int end, int in)
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

    void updateUtils(int start, int end, int in, int ind, int val)
    {
        if (start == ind&& end ==ind)
        {
            tree[in] = val;
            arr[ind] = val;
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

public:
    SegmentTree(vector<int> data)
    {
        n = data.size();
        arr = data;
        int h = (int)ceil(log2(n));
        int size = 2 * pow(2, h);

        tree.resize(size, 0);
        buildtree(0, n - 1, 1);
    }

    void update(int ind){
        return updateUtils(0, n - 1, 1, ind, 0);
    }

    int query(int kth){
        if(tree[1]<kth)return 1;

        int temp = queryUtils(0,n-1,1,kth);

        return temp;

    }

    void print()
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
        cout<<"\n";
    }
};