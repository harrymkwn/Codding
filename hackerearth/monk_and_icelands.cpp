#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007


int  bfs(vector<vector<int>> &graph, int sv, vector<bool>visited,int n)
{
    queue<pair<int,int>> q;
    q.push({sv,0});
    visited[sv] = true;
    pair<int,int> ele;
    while (!q.empty()){
        ele = q.front();
        // cout << ele.first << " ";
        if(ele.first==n)return ele.second;
        q.pop();
        for (int cv : graph[ele.first]){
            if (!visited[cv]){
                visited[cv] = true;
                q.push({cv,ele.second + 1});
            }
        }
    }
    return -1;
}
int main(){

    int n;
    cin>>n;
    while (n--)
    {
        int n,e,x,y;
        cin>>n>>e;
        vector<vector<int>> graph(n);
        F(0,e,i){
            cin>>x>>y;
            graph[x-1].push_back(y-1);
            graph[y-1].push_back(x-1);
        }
        vector<bool> visited(n,false);
        cout<<bfs(graph,0,visited,n-1)<<"\n";
    }
    
  return 0;
}