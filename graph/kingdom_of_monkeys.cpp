#include <bits/stdc++.h>
using namespace std;

long long dfs(vector<vector<int>> edges, long long *arr, bool *visited, int sv,int n)
{
    visited[sv] = true;
    long long sum = arr[sv];
    for (int i = 0; i < edges[sv].size(); i++)
    {
        if(i==sv)continue;
        if(edges[sv][i]) {
            if (!visited[i]) {
                sum += dfs(edges, arr, visited, i, n);
            }
        }
    }
    return sum;
}

long long find(vector<vector<int>> edges, long long *arr, int n)
{
    long long a = 0;
    bool *visited = new bool[n];
    memset(visited, false, n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            a = max(a, dfs(edges, arr, visited, i,n));
    }
    return a;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
            edges[y - 1].push_back(x - 1);
        }
        long long arr[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << find(edges, arr, n);
    }
}