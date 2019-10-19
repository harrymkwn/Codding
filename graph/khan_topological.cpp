#include <bits/stdc++.h>
using namespace std;

void topologicalsort(vector<int> *adj, int n, int e, int *indegree)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(indegree[i]==0)q.push(i);
    }

    int count=0;
    vector<int> sort;
    while (!q.empty())
    {
        int u =q.front();
        q.pop();
        sort.push_back(u);

        for(int i=0;i<adj[u].size();i++)
        {
            if(--indegree[adj[u][i]]==0)q.push(adj[u][i]);
        }
        if(++count>=n)break;
    }
    for (int i = 0; i < n; i++)
    {
        cout<< sort[i] << " ";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> *adj = new vector<int>[n];

    int *indegre = new int[n];
    fill_n(indegre, n, 0);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegre[y] += 1;
    }

    topologicalsort(adj, n, e, indegre);
    delete[] adj;
}