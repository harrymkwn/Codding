#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b)
{
    if (a[0] < b[0] && a[1] < b[1] && a[2] < b[2])
        return true;
    return false;
}

bool availDimensions(vector<int> o,vector<int> c){
    return (c[0] > o[0] && c[1] > o[1] && c[2] > o[2]);
}

vector<vector<int>> diskStacking(vector<vector<int>> disks)
{   
    sort(disks.begin(),disks.end(),[](vector<int> a,vector<int> b){return a[2]<b[2];});
    for (int i = 0; i < disks.size(); i++)
    {
        cout << disks[i][0] << " " << disks[i][1] << " " << disks[i][2] << "\n";
    }
    vector<vector<int>> dp(disks.size(), {0, INT_MIN});
    vector<vector<int>> ret;
    int maxInd = 0;
    dp[0][0] = disks[0][2];
    for (int i = 1; i < disks.size(); i++)
    {
        dp[i][0] = disks[i][2];
        for (int j = 0; j < i; j++)
        {
            if (availDimensions(disks[j],disks[i]))
            {
                if (dp[i][0] <= dp[j][0] + disks[i][2])
                {
                    dp[i][0] = dp[j][0] + disks[i][2];
                    dp[i][1] = j;
                }
            }
        }
        if (dp[maxInd][0] <= dp[i][0]){ maxInd = i; }
    }
    while (dp[maxInd][1] != INT_MIN)
    {
        ret.push_back(disks[maxInd]);
        maxInd = dp[maxInd][1];
    }
    ret.push_back(disks[maxInd]);
    

    sort(ret.begin(), ret.end(), check);
    return ret;
}

int main()
{
    vector<vector<int>> disks = {{2, 1, 2}, {3, 2, 5}, {2, 3, 4}};
    vector<vector<int>> ret = diskStacking(disks);
    cout<<"\n";
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i][0] << " " << ret[i][1] << " " << ret[i][2] << "\n";
    }

    return 0;
}