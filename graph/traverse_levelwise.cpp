#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct node
{
    int value;
    int level;
    node(int v,int l) : value(v),level(l){};
};


void print(int** edges , int n,int sv){
    queue<node> pev;
    bool * visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    node nam(sv,0);
    pev.push(nam);
    visited[nam.value]=true;
    while (!pev.empty())
    {
        node m = pev.front();
        pev.pop();
        cout<<m.value<<" "<<m.level<<endl;
        for (int i = 0; i < n; i++)
        {
            if(i==m.value)
            continue;
            if(edges[m.value][i]==1 && !visited[i]){
                node n(i,m.level+1);
                pev.push(n);
                visited[i] = true;
            }
        }
        
    }
    
}



int main(){
    int n; 
    int e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int [n];
        for(int j=0;j<n;j++)
        edges[i][j]=0;
    }
    int f,s;
    for(int i=0;i<e;i++){
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    print(edges,n,0);
    return 0;
}