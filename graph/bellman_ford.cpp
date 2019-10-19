#include <bits/stdc++.h>
using namespace std;

struct node
{
    int src, dst, weight;

    node() : src(0), dst(0), weight(0) {}
};

struct output
{
    int dist, parent;

    output() : dist(INT_MAX), parent(0) {}
};

void bellmanford(node *edges, int n, int e)
{

    output *dist = new output[n];

    int count = 0;
    dist[0].dist=0;
    while (count < n - 1)
    {
        for (int i = 0; i < e; i++)
        {
            int u = edges[i].src;
            int v = edges[i].dst;
            int wei = edges[i].weight;
            if (dist[u].dist != INT_MAX && dist[v].dist > dist[u].dist + wei)
            {
                dist[v].dist = dist[u].dist + wei;
                dist[v].parent = u;
            }
        }
        count++;
    }

    for (int i = 0; i < n; i++)
        cout << i << " " << dist[i].dist << " " << dist[i].parent << "\n";

    delete[] dist;
}

int main()
{
    int n = 0, e = 0;
    cin >> n >> e;
    node *edges = new node[e];
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].src >> edges[i].dst >> edges[i].weight;
    }
    bellmanford(edges, n, e);
    delete[] edges;
}