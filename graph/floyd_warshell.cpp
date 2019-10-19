#include <bits/stdc++.h>
using namespace std;
#define INF 100000
void floydWarshell(int **edges, int n, int e)
{

    int **path = new int *[n];
    for (int i = 0; i < n; i++)
    {
        path[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                path[i][j] = 0;
            else
                path[i][j] = INT_MAX;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(edges[i][k]==INF || edges[k][j]==INF)continue;
                if (edges[i][j] > edges[i][k] + edges[k][j])
                {
                    edges[i][j] = edges[i][k] + edges[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    for (int l = 0; l < n; l++) {
        for (int i = 0; i < n; i++) {
            cout<<edges[l][i]<<" ";
        }
        cout<<"\n";
    }
}

int main(int argc, char const *argv[])
{
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                edges[i][j] = 0;
            else
                edges[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges[x][y] = w;
    }
    floydWarshell(edges, n, e);
    delete[] edges;
    return 0;
}