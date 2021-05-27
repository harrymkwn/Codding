#include <bits/stdc++.h>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &graph,int sv)
{
    int n = graph.size();
    queue<int> pev;
    vector<bool> isVisited(n,false);

    pev.push(sv);
    isVisited[sv] = true;
    
    while (!pev.empty())
    {
        int cv = pev.front();
        pev.pop();

        for(auto x : graph[cv])
        {
            if(!isVisited[x]){
                pev.push(x);
                isVisited[x] = true;
            }
        }
    }
}

int main()
{
    int n,e,u,v;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(adj,0);

    return 0;
}