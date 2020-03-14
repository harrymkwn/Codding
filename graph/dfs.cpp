#include<bits/stdc++.h>
using namespace std;


// void dfs(int** edges , int n,int sv,int* visited){
//     cout<<sv<<endl;
//     visited[sv]=true;
//     for(int i=0;i<n;i++)
//     {
//         if(i==sv){
//             continue;
//         }
//         if(edges[sv][i]==1 && !visited[i]){
//             dfs(edges,n,i,visited);
//         }
//     }
// }

void dfss(vector<vector<int>>& graph,int sv,vector<bool>& visited){
    visited[sv] = true;
    cout<<sv<<" ";
    for(int cv : graph[sv]){
        if(!visited[cv])
            dfss(graph,cv,visited);
    }
}


// int main(){
//     int n; 
//     int e;
//     cin>>n>>e;

//     int** edges = new int*[n];
//     for(int i=0;i<n;i++){
//         edges[i]=new int [n];
//         for(int j=0;j<n;j++)
//         edges[i][j]=0;
//     }
//     int f,s;
//     for(int i=0;i<e;i++){
//         cin>>f>>s;
//         edges[f][s]=1;
//         edges[s][f]=1;
//     }
//     int* visited = new int[n];
//     fill_n(visited,n,false);
//     dfs(edges,n,0,visited);
// }

int main()
{


vector<int> arr={5,4,3,2,1};
auto n = std::count_if(std::begin(arr), std::end(arr), [](int i) {
  return i>=1;
});
    cout<<n;
    std::sort(std::begin(arr), std::end(arr));

    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    }