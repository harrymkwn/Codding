#include<bits/stdc++.h>
using namespace std;


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n;i++){
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }
    
    
    vector<bool> visited(n,false);
    multiset<vector<int>> s;

    s.insert({0,src,K+1});

    while(!s.empty()){
        vector<int> p = *s.begin();
        s.erase(s.begin());

        int ds = p[0];
        int u = p[1];
        int stepsRemaining = p[2];

        if(visited[u] || stepsRemaining<0)continue;
        visited[u]=true;
        
        if(u==dst)return ds;

        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first, d = adj[u][i].second;            
            s.insert({ds+d,v,stepsRemaining-1});
        }
    }

    return -1;
}


int main(){
    
    return 0;
}