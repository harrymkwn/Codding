#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph,int sv,vector<bool> &isVisited,vector<int> &temp){

    isVisited[sv] = true;
    temp.push_back(sv);

    for(auto x: graph[sv]){
        if(!isVisited[x]){
            dfs(graph,x,isVisited,temp);
        }
    }

}

vector<vector<int>> findComponents(vector<vector<int>> &graph){

    int n=graph.size();
    vector<vector<int>> components;
    vector<bool> isVisited(n,false);
    for(int i=0;i<n;i++){
        if(!isVisited[i]){
            vector<int> temp;
            dfs(graph,i,isVisited,temp);
            components.push_back(temp);
        }
    }
    return components;
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

    vector<vector<int>> components = findComponents(adj);
    return 0;
}