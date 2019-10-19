#include <bits/stdc++.h>
using namespace std;

void findEularPath(int **edges, int n)
{
    int count=0;
    int start_point=0;
    int *sumind = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        sumind[i] = accumulate(edges[i], edges[i] + n, 0);
        if(sumind[i]%2==1){count++;
        start_point=i;}
    }
    if(count>2){
        cout<<"no eulerian path\n";
        return;
    }
    stack<int> s;
    vector<int>path;
    int cur = start_point;
    while (!s.empty() || accumulate(edges[cur],edges[cur]+n,0)!=0)
    {
        if(accumulate(edges[cur],edges[cur]+n,0)==0){
            path.push_back(cur+1);
            cur = s.top();
            s.pop();
        }
        else{
            for (size_t i = 0; i < n; i++)
            {
                if(edges[cur][i]==1){
                    s.emplace(cur);
                    edges[cur][i]=0;
                    edges[i][cur]=0;
                    cur = i;
                    break;
                }
            }        
        }
    }
    std::cout <<path.size()<< std::endl;
    for (size_t i = 0; i < path.size(); i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<cur+1;
    
}

int main()
{
    int n;
    cin >> n;
    int **edges = new int *[n];
    for (size_t i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (size_t j = 0; j < n; j++)
            cin >> edges[i][j];
    }

    findEularPath(edges, n);
}