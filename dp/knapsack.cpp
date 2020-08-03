#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> knapSackHelper(vector<vector<int>> dp, vector<vector<int>> items, int capacity)
{

    vector<vector<int>> ret = {{}, {}};

    int max = dp[items.size()][capacity];
    int i = items.size();
    int c = capacity;
    while (i > 0)
    {
        if (dp[i][c] == dp[i - 1][c])
            i--;
        else
        {
            ret[1].insert(ret[1].begin(), i - 1);
            i--;
            c -= items[i][1];
        }
        if (c == 0)
            break;
    }
    ret[0].push_back(max);
    return ret;
}

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity)
{

    vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= items.size(); i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (items[i - 1][1] <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j - items[i - 1][1]] + items[i - 1][0]);
        }
    }
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return knapSackHelper(dp, items, capacity);
}

int main()
{
    vector<vector<int>> items = {{465, 100}, {400, 85}, {255, 55}, {350, 45}, {650, 130}, {1000, 190}, {455, 100}, {100, 25}, {1200, 190}, {320, 65}, {750, 100}, {50, 45}, {550, 65}, {100, 50}, {600, 70}, {240, 40}};
    int capacity = 200;
    vector<vector<int>> ret = knapsackProblem(items, capacity);

    cout << ret[0][0] << "\n";
    for (int i = 0; i < ret[1].size(); i++)
    {
        cout << ret[1][i] << " ";
    }
}