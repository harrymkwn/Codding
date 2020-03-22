#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

template<typename T>
void vp(T a){
    cout<<"\n";
    for(int i=0;i<a.size();i++){
        cout<<a[i].s<<" "<<a[i].d << " "<<a[i].w<<"\n";
    }
}
struct edge
{
    int s,d,w;
    edge() : s(0),d(0),w(0){};
};

bool check(edge a,edge b){
    if(a.w != b.w)return a.w< b.w;
    else if (a.d!= b.d) return a.d < b.d;
    else a.s<b.s;
}

int find(vector<int> parent, int point)
{
    while (parent[point] != point)
        point = parent[point];

    return point;
}

vector<edge> kruskal(vector<edge> edges ,vector<bool> visited,int e,int sv){
    
    sort(edges.begin(),edges.end(),check);
    
    vector<edge> mst;
    vector<int> parent(e+1,-1);
    F(0,e+1,i)parent[i]=i;
    int count=0,i=0;
    while (count < e)
    {
        int ps = find(parent,edges[i].s);
        int pd = find(parent,edges[i].d);

        if(ps!= pd){
            mst.push_back(edges[i]);
            count++;
            parent[pd] = ps;
        }
        i++;
    }
    return mst;
}

int main(){
    int n, e, x, y, w;
    cin >> n >> e;
    vector<edge> edges(e);
    F(0, e, i){
       cin >> edges[i].s >> edges[i].d >> edges[i].w;
    }
    vector<bool> visited(n, false);
    vector<edge> mst = kruskal(edges,visited,n-1,0);
    vp(mst);
    return 0;
}