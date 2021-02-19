#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> grid,int n,int m,int i,int j){
    return (i>=0 && j>=0 && i<n && j<m && grid[i][j]!=-1);
}

int maxpath(vector<vector<int>> grid,int n,int m,int i,int j){
    if(!isValid(grid,n,m,i,j))return 0;

    int down=0,other=0;
    if(i%2==0){
        down = maxpath(grid,n,m,i+1,j);
        other = maxpath(grid,n,m,i,j+1);
    }
    else
    {
        down = maxpath(grid,n,m,i+1,j);
        other = maxpath(grid,n,m,i,j-1);    
    }

    return max(down,other) + grid[i][j];
    
}

int main(){
    vector<vector<int>> grid;
    int n,m;
    cin>>n>>m;
    grid.resize(n,vector<int>(m,0));    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>grid[i][j];

    cout<<maxpath(grid,n,m,0,0)<<"\n";
    return 0;
}