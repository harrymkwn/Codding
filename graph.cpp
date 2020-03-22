#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

template <typename T>
void vp(T a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

vector<int> restore_path(vector<int>& p,int sv,int ev){

    vector<int> path;
    for (int i = ev; i != sv; i = p[i]) 
    {
        path.push_back(i);
    }
    path.push_back(sv);
    reverse(path.begin(),path.end());
    return path;
    
}

int dijkstra(vector<vector<pair<int, int>>> &graph, vector<bool> visited, int sv, int ev)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(graph.size(), INT_MAX);
    vector<int> p(graph.size(),-1);
    dist[sv] = 0;
    p[sv]=sv;
    q.push({0, sv});
    pair<int, int> ele;
    while (!q.empty())
    {
        ele = q.top();
        q.pop();
        for (auto cv : graph[ele.second])
        {
            if (dist[ele.second] + cv.second < dist[cv.first])
            {
                dist[cv.first] = dist[ele.second] + cv.second;
                q.push({dist[cv.first], cv.first});
                p[cv.first] = ele.second;
            }
        }
    }
    vector<int> path = restore_path(p,sv,ev);
    vp(path);
    return dist[ev];
}

int main()
{
    int n, e, x, y, w;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n);
    F(0, e, i){
       cin >> x >> y >> w;
       graph[x - 1].push_back({y - 1, w});
       graph[y - 1].push_back({x - 1, w});
    }
    vector<bool> visited(n, false);
    cout << dijkstra(graph, visited, 0, 4);
    return 0;
}