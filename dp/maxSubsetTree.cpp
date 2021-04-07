#include<bits/stdc++.h>
using namespace std;
/* Given a tree T of N nodes, where each node i has Ci coins attached with it. You have to choose a subset of nodes such that 
** no two adjacent nodes(i.e. nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen 
** subset is maximum.
**
*/

void dfs(vector<vector<int>>  &graph, vector<vector<int>> &dp,int v,int parent){


    int sum1{0}, sum2{0};

    for(auto x: graph[v]){
        if(x==parent)continue;
        
        dfs(graph,dp,x,v);
        sum1 += dp[1][x];
        sum2 += max(dp[0][x],dp[1][x]);
    }

    dp[0][v] = v + sum1;
    dp[1][v] = sum2;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> graph(n);
    vector<vector<int>> dp(2,vector<int>(n,0));
    int u,v;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }    

    dfs(graph,dp,0,-1);
    return 0;
}