#include<bits/stdc++.h>
using namespace std;

class dikstra
{
private:
    int V;

    vector<pair<int,int>> * adj;
public:
    dikstra(int v);

    void addEdge(int u,int v , int w);
    void short_path(int src);
    ~dikstra();
};

dikstra::dikstra(int v)
{
    this->V = v;

    adj = new vector<pair<int,int>>[v];
}

void dikstra::addEdge(int u,int v ,int w){

    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));

}

dikstra::~dikstra()
{
    delete[] adj;
}

void dikstra::short_path(int src){

    vector<int> dist(this->V,INT_MAX);

    priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;

    dist[src]=0;

    pq.push(make_pair(0,src));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v] , v));
            }
        }
    }
    for (int i = 0; i < this->V; i++)
    {
        cout<<i<<" "<<dist[i]<<"\n";
    }
}


int main() 
{ 
    int V = 9; 
    dikstra g(V); 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.short_path(0); 
  
    return 0; 
} 
