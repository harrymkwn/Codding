#include <bits/stdc++.h>
using namespace std;

int minNumberOfJumps(vector<int> array)
{

    vector<int> dp(array.size(), INT_MAX);
    dp[array.size() - 1] = 0;
    for (int i = array.size() - 2; i >= 0; i--)
    {
        if (i + array[i] >= array.size())
            dp[i] = 1;
        else
        {
            for (int j = i + 1; j <= i + array[i]; j++)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[0];
}

int main()
{
    cout << minNumberOfJumps({3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3}) << "\n";
    return 0;
}