//
// Created by harry on 11/5/19.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

class graph
{
    int n, e;

public:
    graph(int n, int e);
    void dfs(int **edges, int n);
    void bfs(int **edges, int n);
    int PrintDFS(int **edges, int n, int sv, bool *visited);
    void PrintBFS(int **edges, int n, int sv, bool *visited);
    void path(int **edges, int s, int d);
    bool haspath(int **edges, int s, bool *visited, int d);
    void pathbetweentwo(int **edges, int s, int d);
    void findpath(int **edges, int n, int s, int d, bool *visited, int *path, int &path_index);
};

#endif //UNTITLED_GRAPH_H
