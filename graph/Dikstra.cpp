#include <bits/stdc++.h>
using namespace std;

int minvertex(int *dist, bool *visited, int n)
{
    int min_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min_index == -1 || dist[i] < dist[min_index]))
        {
            min_index = i;
        }
    }
    return min_index;
}

void dikstra(int **edges, int n, int src)
{
    bool *visited = new bool[n];
    memset(visited, false, n);

    int *dist = new int[n];
    fill_n(dist, n, INT_MAX);
    dist[src] = 0;

    int count = 0;
    while (count < n - 1)
    {
        int u = minvertex(dist, visited, n);
        visited[u] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[u][j] && !visited[j] && dist[u] + edges[u][j] < dist[j])
                dist[j] = dist[u] + edges[u][j];
        }
        count++;
    }

    for (int j = 0; j < n; j++)
    {
        cout << j << " " << dist[j] << "\n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n + 1];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n + 1];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges[x][y] = w;
        edges[y][x] = w;
    }
    dikstra(edges, n, 0);
}