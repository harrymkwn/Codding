#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<int> arr,tree;

    void updateUtils(int start, int end, int in, int ind)
    {
        if (start == ind&& end ==ind)
        {
            tree[in]++;
            return;
        }

        int mid = (start + end) > 1;
        if (ind <= mid)
            updateUtils(start, mid, 2 * in, ind, val);
        else
            updateUtils(mid + 1, end, 2 * in + 1, ind, val);

        tree[in] = tree[2 * in] + tree[2 * in + 1];
    }

    int queryUtils(int start, int end, int in,int l,int r)
    {
        if(end <l || start >r )return 0;

        if(l <= start && end<=r)return tree[in];

        int mid = (start + end) >> 1;
        return queryUtils(start,mid,2*in,l,r) + queryUtils(mid+1,end,2*in+1,l,r);
    }

    init(vector<int> data)
    {
        n = *max_element(data.begin(),data.end());
        int h = (int)ceil(log2(n));
        int size = pow(2, h+1);

        tree.resize(size, 0);
    }

    void update(int ind){
        return updateUtils(0, n - 1, 1, ind);
    }

    int query(int l,int r){

        return queryUtils(0,n-1,1,l,r);
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
public:
    int reversePairs(vector<int>& nums) {
        init(nums);
        print();
    }
};