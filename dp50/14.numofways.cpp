#include <bits/stdc++.h>
using namespace std;

int numofways(vector<vector<int>> grid, int n, int m, int cost, unordered_map<string, int> &mp)
{

    if (n == 0 || m == 0)
        return 0;

    if (n == 1 && m == 1)
        if (cost == grid[n - 1][m - 1])
            return 1;
        else
            return 0;

    string key = to_string(n) + "|" + to_string(m) + "|" + to_string(cost);
    if (!mp[key]){
        mp[key] = numofways(grid,n-1,m,cost-grid[n-1][m-1],mp) + numofways(grid,n,m-1,cost-grid[n-1][m-1],mp);
    }
    return mp[key];
}

int main()
{
    vector<vector<int>> grid;
    unordered_map<string, int> mp;
    int n, m;
    cin >> n >> m;
    grid.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int cost;
    cin >> cost;
    cout << numofways(grid, n, m, cost, mp) << "\n";
    return 0;
}