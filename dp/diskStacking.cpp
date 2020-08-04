#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b)
{
    if (a[0] < b[0] && a[1] < b[1] && a[2] < b[2])
        return true;
    return false;
}

vector<vector<int>> diskStacking(vector<vector<int>> disks)
{
    vector<vector<int>> dp(disks.size(), {0, INT_MIN});
    vector<vector<int>> ret;
    int maxInd = 0;
    for (int i = 1; i < disks.size(); i++)
    {
        dp[i][0] = disks[i][2];
        dp[i][1] = i;
        for (int j = 0; j < i; j++)
        {
            if (disks[i][0] > disks[j][0] && disks[i][1] > disks[j][1] && disks[i][2] > disks[j][2])
            {
                if (dp[i][0] <= dp[j][0] + disks[i][2])
                {
                    dp[i][0] = dp[j][0] + disks[i][2];
                    dp[i][1] = j;
                }
            }
            if (dp[i][0] < disks[j][2]){
                dp[i][0] = disks[j][2];
                dp[i][1] = j;
            }
            if (dp[maxInd][0] <= dp[i][0])
                maxInd = i;
        }
    }
    while (dp[maxInd][1] != INT_MIN)
    {
        ret.push_back(disks[maxInd]);
        maxInd = dp[maxInd][1];
    }

    sort(ret.begin(), ret.end(), check);
    return ret;
}

int main()
{
    vector<vector<int>> disks = {{2,1,2},{3,2,3},{2,2,8},{2,3,4},{2,2,1},{4,4,5}};
    vector<vector<int>> ret = diskStacking(disks);

    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i][0] << " " << ret[i][1] << " " << ret[i][2] << "\n";
    }

    return 0;
}