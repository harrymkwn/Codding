#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int bfs(vector<vector<int>> &graph, int sv, vector<bool>visited,int l)
{
    queue<pair<int,int>> q;
    q.push({sv,l});
    visited[sv] = true;
    pair<int,int> ele;
    int count=0;
    while (!q.empty()){
        ele = q.front();
        if(ele.second==0)count++;
        else if(ele.second<0)return count;
        q.pop();
        for (int cv : graph[ele.first]){
            if (!visited[cv]){
                visited[cv] = true;
                q.push({cv,ele.second-1});
            }
        }
    }
    return count;
}


int main(){

    int n,e,x,y;
    cin>>n>>e;
    vector<vector<int>> graph(n);
    F(0,e,i){
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    vector<bool> visited(n+1,false);
    int  N,l;
    cin>>N;
    F(0,N,i){
        cin>>x>>l;
        cout<<bfs(graph,x-1,visited,l)<<"\n";
        visited.assign(n+1,false);
    }
    return 0;
}