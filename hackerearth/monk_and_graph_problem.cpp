#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int dfs(vector<vector<int>> &graph, int sv, vector<bool>& visited, int &count)
{
    visited[sv] = true;
    count +=graph[sv].size();
    
    // cout<<sv<<" ";
    for (int cv : graph[sv])
    {
        if (!visited[cv])
            dfs(graph, cv, visited, count);
    }
}
int main()
{
    int n, e, x, y;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    F(0, e, i)
    {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }
    vector<bool> visited(n, false);
    int val= 0, count = 0,maxi=0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count = 0;
            dfs(graph, i, visited, count);
            val = max(val,count/2);
        }
    }
    std::cout<<val;
    return 0;
}