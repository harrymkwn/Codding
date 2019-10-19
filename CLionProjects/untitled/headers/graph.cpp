//
// Created by harry on 11/5/19.
//

#include "graph.h"
#include <bits/stdc++.h>
using namespace std;



int graph::PrintDFS(int **edges, int n, int sv, bool *visited) {
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i])
                continue;
            PrintDFS(edges,n,i,visited);
        }
    }
}



void graph::dfs(int **edges, int n) {
    bool * visited = new bool[n];

    for(int i=0;i<n;i++)
        visited[i]= false;

    for(int i=0;i<n;i++)
        if(!visited[i])
            PrintDFS(edges,n,i,visited);

    cout<<endl;
}




void graph::PrintBFS(int** edges , int n,int sv,bool * visited){
    queue<int> pev;
    pev.push(sv);
    visited[sv]=true;
    while (!pev.empty())
    {
        int cv = pev.front();
        pev.pop();
        cout<<cv<<endl;
        for (int i = 0; i < n; i++)
        {
            if(i==cv)
                continue;
            if(edges[cv][i]==1 && !visited[i]){
                pev.push(i);
                visited[i] = true;
            }
        }

    }

}

void graph::bfs(int **edges, int n) {
    bool * visited = new bool[n];

    for(int i=0;i<n;i++)
        visited[i]= false;

    for(int i=0;i<n;i++)
        if(!visited[i])
            PrintBFS(edges,n,i,visited);

    cout<<endl;
}

void graph::findpath(int** edges, int n,int s,int d,bool * visited,int* path,int &path_index){
    visited[s]= true;
    path[path_index];
    path_index++;

    if(s==d){
        for(int i=0;i<path_index;i++)
            cout<<path[i]<<" ";
        cout<<endl;
    } else{
        for(int i=0;i<n;i++)
            if(!visited[i])
                findpath(edges,n,i,d,visited,path,path_index);
    }

    visited[s]= false;
    path_index--;

}

void graph::pathbetweentwo(int** edges,int s,int d) {

    bool * visited = new bool[n];

    for(int i =0;i<n;i++)
        visited[i]= false;

    int *path = new int[n];
    int path_index=0;

    findpath(edges,n,s,d,visited,path,path_index);

}





bool graph::haspath(int **edges , int s, bool *visited,int d) {


    queue<int> pev;
    pev.push(s);
    visited[s]=true;
    while (!pev.empty())
    {
        int cv = pev.front();
        pev.pop();
        if(cv==d)
            return true;
        cout<<cv<<endl;
        for (int i = 0; i < n; i++)
        {
            if(i==cv)
                continue;

            if(edges[cv][i]==1 && !visited[i]){
                pev.push(i);
                visited[i] = true;
            }
        }

    }
    return false;
}

void graph::path(int**edges,int s,int d) {
    bool * visited = new bool[n];

    for(int i=0;i<n;i++)
        visited[i]= false;

   string o = (haspath(edges,s,visited,d)) ? "has path between that two vertices" : "no path between that two vertices";
    cout<<o<<endl;
}

graph::graph(int n,int e){
    this->n = n;
    this->e = e;
    int** edges = new int*[this->n];

    for(int i=0;i<this->n;i++){
        edges[i]=new int [n];
        for(int j=0;j<this->n;j++)
            edges[i][j]=0;
    }
    int f,s;
    for(int i=0;i<this->e;i++){
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    pathbetweentwo(edges,3,6);
}
