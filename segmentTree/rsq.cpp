#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    int n;
    vector<int> data, tree;

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        for (auto x : nums)
            data.push_back(x);

        int h = (int)ceil(log2(n));
        int size = 2* pow(2, h);

        tree.resize(size);
        buildtree(0, n - 1, 1);
    }

    void buildtree(int start, int end, int in)
    {
        if (start == end)
        {
            tree[in] = data[start];
            return;
        }

        int mid = (start + end) >> 1;
        buildtree(start, mid, 2 * in);
        buildtree(mid + 1, end, 2 * in + 1);

        tree[in] = tree[2 * in] + tree[2 * in + 1];
    }

    void updateUtil(int start, int end, int in, int index, int val)
    {
        if (start == index && end==index)
        {
            tree[in] = val;
            data[index] = val;
            return;
        }

        int mid = (start + end) >> 1;

        if (index <= mid)
            updateUtil(start, mid, 2 * in, index, val);
        else
            updateUtil(mid + 1, end, 2 * in + 1, index, val);

        tree[in] = tree[2 * in] + tree[2 * in + 1];
    }
    void update(int index, int val)
    {
        updateUtil(0, n - 1, 1, index, val);
    }

    int SumRangeUtil(int start, int end, int left, int right, int in)
    {

        if (right < start || left > end)
            return 0;

        if (left <= start && end <= right)
            return tree[in];

        int mid = (start + end) >> 1;

        return SumRangeUtil(start, mid, left, right, 2 * in) + SumRangeUtil(mid + 1, end, left, right, 2 * in + 1);
    }

    int sumRange(int left, int right)
    {
        return SumRangeUtil(0, n - 1, left, right, 1);
    }
};