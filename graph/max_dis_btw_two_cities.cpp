#include <bits/stdc++.h>
using namespace std;

struct node
{
    int dst, weight;

    node(int y, int w) : dst(y), weight(w) {}
};

class graph
{
private:
    int n, e, src;
    vector<node> *adj;
    vector<int> arr;
    int *dist;
public : graph(int n, int e);
    ~graph();
    void topoutil(bool *visited, stack<int> &s, int cv);
    void maxdist();
};

graph::graph(int n, int e)
{
    this->n = n;
    this->e = e;
    adj = new vector<node>[n];
    dist = new int[n];
    fill_n(dist, n, INT_MIN);

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(node(y, w));
    }

    cout << "\n Enter the number where you want to find maximum distance : ";
    cin >> src;
    dist[src] = 0;
}

graph::~graph()
{
    delete[] adj;
    delete[] dist;
}

void graph::topoutil(bool *visited, stack<int> &s, int cv)
{
    visited[cv] = true;

    for (int i = 0; i < adj[cv].size(); i++)
    {
        if (!visited[adj[cv][i].dst])
            topoutil(visited, s, adj[cv][i].dst);
    }

    s.push(cv);
}

void graph::maxdist()
{

    stack<int> s;
    bool *visited = new bool[n];
    memset(visited, false, n);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topoutil(visited, s, i);
    }

    while (!s.empty())
    {
        int u = s.top();
        cout<<u<<" ";
        s.pop();
        if (dist[u] != INT_MIN)
        {
            for (int i = 0; i < adj[u].size(); i++)
            {
            if(dist[adj[u][i].dst] < dist[u] + adj[u][i].weight)
                dist[adj[u][i].dst] = dist[u] + adj[u][i].weight;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        (dist[i] == INT_MIN)?cout<<"INF " : cout<<dist[i]<<" ";
    }

    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;
    graph g(n, e);
    g.maxdist();
}