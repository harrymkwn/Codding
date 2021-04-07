#include <bits/stdc++.h>
using namespace std;


void dfsUtils(vector<vector<int>> &graph, int sv, vector<bool> &visited)
{
    visited[sv] = true;
    cout << sv << " ";
    for (int cv : graph[sv])
    {
        if (!visited[cv])
            dfsUtils(graph, cv, visited);
    }
}

void dfs(vector<vector<int>> &graph){
    int  n = graph.size();
    vector<bool> isVisited(n,false);

    for(int i=0;i<n;i++){
        if(!isVisited[i])dfsUtils(graph,i,isVisited);
        //dfsIterative(graph,i);
    }

}

void dfsIterative(vector<vector<int>> &graph,int sv){

    int n = graph.size();
    stack<int> s;
    vector<bool> isVisited(n,false);
    s.push(sv);
    isVisited[sv] = true;


    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        for(auto x : graph[temp]){
            if(!isVisited[x]){s.push(x);isVisited[x]=true;}
        }
    }
    
}

int main(){
    int n,e,u,v;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj);

    return 0;
}
