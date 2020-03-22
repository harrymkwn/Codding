#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int bfs(vector<vector<int>> &graph, int sv, vector<bool>visited,vector<bool> girls)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,sv});
    visited[sv] = true;
    pair<int,int> ele; 
    while (!q.empty()){
        ele = q.top();
        cout << ele.second << " ";
        if(girls[ele.second])return ele.second;
        q.pop();
        for (int cv : graph[ele.second]){
            if (!visited[cv]){
                visited[cv] = true;
                q.push({ele.first+1 , cv});
            }
        }
    }
    cout<<"\n";
}

int main(){
    int n,e,x,y;
    cin>>n;
    vector<vector<int>> graph(n);
    F(0,n-1,i){
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    // F(0,n-1,i)sort(graph[i].begin(),graph[i].end());
    vector<bool> visited(n,false);
    int q;
    vector<bool> girls(n);
    cin>>q;
    F(0,q,i){
        cin>>x;
        girls[x-1]=true;
    }
    cout<<"\n"<< bfs(graph,0,visited,girls) + 1;
    return 0;
}