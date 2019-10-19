#include <bits/stdc++.h>
using namespace std;

void topoutil(vector<int> *adj, int n, bool *visited, stack<int> &s,int cv)
{
    visited[cv]=true;

    for (int i = 0; i < adj[cv].size(); i++)
    {
        if(!visited[adj[cv][i]])
            topoutil(adj,n,visited,s,adj[cv][i]);
    }

    s.push(cv);
    
}

void topologicalsort(vector<int> *adj, int n, int e)
{

    stack<int> s;
    bool *visited = new bool[n];
    memset(visited, false, n);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topoutil(adj, n, visited, s,i);
    }
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> *adj = new vector<int>[n];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    topologicalsort(adj, n, e);
    delete[] adj;
}