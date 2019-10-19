#include <bits/stdc++.h>
using namespace std;

class graph{

private:

    int n=0;
    vector<pair<int,int>>* adj;
    int start=0;
public:
    graph(int N,int e);
    void addEdge(int x,int y,int w);
    void prims();
    ~graph();
};


graph::graph(int N,int e){
    this->n = N;
    adj = new vector<pair<int,int>>[n];

    int x,y,w;
    for(int i=0;i<e;i++){
        cin>>x>>y>>w;
        addEdge(x-1,y-1,w);
    }
    cin>>start;
}

void graph::addEdge(int x,int y,int w){

    adj[x].push_back(make_pair(y,w));
    adj[y].push_back(make_pair(x,w));
}

void graph::prims() {

    vector<int>key(n,INT_MAX);
    vector<int>parent(n,-1);
    vector<bool>visited(n,false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.emplace(make_pair(0,start));
    key[start]=0;

    while(!pq.empty()){
        pair<int,int> top = pq.top();
        pq.pop();

        int u = top.second;
        visited[u]=true;

        for(int i=0;i<adj[u].size();i++){

            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if(!visited[v] && key[v] >weight){
                key[v] = weight;
                pq.push(make_pair(weight,v));
                parent[v] =u;
            }
        }
    }
    int total=0;
    for(int i=0;i<n;i++){
        if(key[i]!=INT_MAX)
            total+= key[i];
    }
    cout<<total<<"\n";

}

graph::~graph(){
    delete [] adj;
}

int main()
{
    int n,e;
    cin>>n>>e;
    graph g(n,e);

    return 0;
}

