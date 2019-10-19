#include <iostream>
using namespace std;
#include<vector>

bool PrintDFS(int **edges, int n, int sv, bool *visited,vector<int>&s,int end) {
    s.push_back(sv);
    if(sv==end)
        return true;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i])
                continue;
            if(PrintDFS(edges,n,i,visited,s,end))
                return true;
        }
    }
}



int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    int** edges = new int*[V];

    for(int i=0;i<V;i++){
        edges[i]=new int [E];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    int f,s;
    for(int i=0;i<E;i++){
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int start,end;
    cin>>start>>end;
    vector<int> str;
    bool * visited = new bool[V];

    for(int i=0;i<V;i++)
        visited[i]= false;
    if(PrintDFS(edges,V,start,visited,str,end)){
        for(int i=0;i<str.size();i++)
            cout<<str[i]<<" ";
    }
        

  return 0;
}
