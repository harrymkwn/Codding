#include<bits/stdc++.h>
using namespace std;

struct node
{
    int vertex;
    int dis;
    node(int v,int d) : vertex(v),dis(d){}
};


int bfs(vector<int>* edges,int x,int sv)
{
        bool* visited = new bool[x];
        memset(visited,false,x);

        queue<node>q;

        node temp(sv,0);
        q.emplace(temp);
        visited[temp.vertex]=1;

        while (!q.empty())
        {
            node t = q.front();
            q.pop();

            if(t.vertex==x-1)return t.dis;

            for(int i=0;i<edges[t.vertex].size();i++){
                if(!visited[edges[t.vertex][i]]){
                    visited[edges[t.vertex][i]]=true;
                    
                    node a(edges[t.vertex][i],t.dis +1);
                    q.push(a);
                }
            }
        }
        return -1;
        
    
}

int main()
{
	int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        vector<int> edges[x];
        for(int i=0;i<y;i++)
        {
            int p,q;
            cin>>p>>q;
            edges[p-1].push_back(q-1);
            edges[q-1].push_back(p-1);
        }
        int ret = bfs(edges,x,0);
        if(ret!=-1)
            cout<<ret<<"\n";
        else
            cout<<"not found";        
    }
	return 0;
}
