#include<bits/stdc++.h>
using namespace std;
bool flag=false;

void print(int* path,int path_index){

    do{
        cout<<path_index<<" ";
        path_index=path[path_index];
    }while (path[path_index]!=path_index);
    cout<<path_index;
    
}

void PrintBFS(int ** edges,int n,int sv,int ev){

    int* path = new int[n];
    for(int i=0;i<n;i++)path[i]=i;
    bool * visited = new bool[n];

    for(int i=0;i<n;i++)
        visited[i]= false;

    queue<int>q;

    q.push(sv);
    visited[sv]=true;
    path[sv]=sv;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for(int i=0;i<n;i++){
            if(edges[top][i] && !visited[i])
            {
                visited[i]=true;
                q.push(i);
                path[i]=top;
                if(i==ev){print(path,i);flag=1;break;}
            }
        }
        if(flag)break;
    }
    

    delete[] path;
    delete[] visited;
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
    PrintBFS(edges,V,start,end); 

    for(int i=0;i<V;i++)
        delete[] edges[i];

    delete[] edges;
  return 0;
}