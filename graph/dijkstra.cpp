#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int sv)
{

    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    vector<bool> isVisited(n, false);

    pq.push({0, sv});
    dist[sv] = 0;

    while (!pq.empty())
    {
        pair<int, int> cv = pq.top();
        pq.pop();

        int u = cv.second;
        int d = cv.first;
        if (isVisited[u])
            continue;
        isVisited[u] = true;

        for (auto x : graph[u])
        {
            int v = x.first, dc = x.second;

            if (dist[v] > d + dc)
            {
                dist[v] = d + dc;
                pq.push({dist[v], v});
            }
        }
    }

    // here dist array contains all shortest distance from source node
}

int main()
{
    int n,e,u,v,w;
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(adj,0);
}