#include<bits/stdc++.h>
using namespace std;

class topo
{
private:
    int n;
    int e;
    vector<int>* adj;
    int* indegree;
public:
    topo(int n,int e);
    ~topo();
    void topological();
    void topologicalutil(vector<int>& res , bool* visited);
};

topo::topo(int n,int e)
{
    this->n=n;
    this->e=e;
    indegree = new int[n];
    fill_n(indegree,n,0);
    adj = new vector<int>[n];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
}

topo::~topo()
{
    delete[]  adj;
}

void topo::topological(){

    bool* visited = new bool[n];
    memset(visited,false,n);

    vector<int> res;
    topologicalutil(res,visited);
}

void topo::topologicalutil(vector<int>& res , bool* visited){

    bool flag=false;
    
    for (int i = 0; i < n; i++)
    {
        if(indegree[i]==0 && !visited[i]){
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]--;
            }

            res.push_back(i);
            visited[i]=true;
            topologicalutil(res,visited);

            res.erase(res.end()-1);
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
            visited[i]=false;
            flag = true;
        }
    }
    if(!flag){
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }

}


int main(){
    int n,e;
    cin>>n>>e;
    topo graph(n,e);

    graph.topological();
}