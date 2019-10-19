#include <bits/stdc++.h>
#include <queue>
using namespace std;

void print(int **edges, int n, int sv)
{
    queue<int> pev;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    pev.push(sv);
    visited[sv] = true;
    while (!pev.empty())
    {
        int cv = pev.front();
        pev.pop();
        cout << cv << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == cv)
                continue;
            if (edges[cv][i] == 1 && !visited[i])
            {
                pev.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    print(edges, n, 0);
    return 0;
}