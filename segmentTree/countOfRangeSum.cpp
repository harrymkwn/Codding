#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {

        map<long long ,long long> mp;

        long long n = nums.size(),c=0,sum=0;

        for(int i=0;i<n;i++){
            sum += nums[i];

            for(int j=lower;j<=upper;j++){
                if(j==sum)c++;

                c+= mp[sum-j];
            }
            mp[sum]++;
        }

        return c;
    }
};