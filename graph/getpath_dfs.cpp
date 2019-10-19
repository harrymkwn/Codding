#include<bits/stdc++.h>
using namespace std;
bool flag=false;

void print(int* path,int path_index){

    for(int i=path_index-1;i>=0;i--)
        cout<<path[i]<<" ";
}

void PrintDFSUtil(int** edges,int n,int cv,int ev,bool* visited,int* path,int path_index){
    visited[cv]=true;
    path[path_index]=cv;
    path_index++;

    if(cv==ev){
        flag =1;
        print(path,path_index);
        return;
    }

    for(int i=0;i<n;i++){
        if(cv==i)continue;
        if(edges[cv][i] && !visited[i] && !flag)
            PrintDFSUtil(edges,n,i,ev,visited,path,path_index);
    }
    if(flag)return;
    path[path_index]=0;
    path_index--;
}


void PrintDFS(int ** edges,int n,int sv,int ev){

    int path[n]={0};
    int path_index=0;
    bool * visited = new bool[n];

    for(int i=0;i<n;i++)
        visited[i]= false;

    if(sv==ev)cout<<"";
    else
       PrintDFSUtil(edges,n,sv,ev,visited,path,path_index);


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
    PrintDFS(edges,V,start,end); 

    for(int i=0;i<V;i++)
        delete[] edges[i];

    delete[] edges;
  return 0;
}
