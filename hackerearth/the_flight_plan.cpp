#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

void bfs(vector<vector<int>> &graph, int x,int y, vector<bool>visited,int t,int c)
{
    queue<pair<int,int>> q;
    q.push({x,1});
    visited[x] = true;
    vector<int> go_through(graph.size(),-1);
    while (!q.empty()){
        pair<int,int> ele = q.front();
        if(ele.first==y){cout<<ele.second<<"\n"; break;}
        q.pop();
        for (int cv : graph[ele.first]){
            if (!visited[cv]){
                visited[cv] = true;
                go_through[cv]=ele.first;
                q.push({cv,ele.second+1});
            }
        }
    }
    int i=y;
    vector<int> arr;
    while (go_through[i]!=-1)
    {   arr.push_back(go_through[i]);
        i = go_through[i];
    }
    f(arr.size()-1,0,i){
        cout<<arr[i]+1<<" ";
    } 
    cout<<y+1;   
}
int main(){
    int n,e,t,c,x,y;
    cin>>n>>e>>t>>c;
    vector<vector<int>> graph(n);
    F(0,e,i){
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    vector<bool> visited(n,false);
    cin>>x>>y;
    bfs(graph,x-1,y-1,visited,t,c);
    return 0;
}