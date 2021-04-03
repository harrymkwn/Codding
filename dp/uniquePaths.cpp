#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    
    vector<vector<int>> dp(m,vector<int>(n,0));

    for(int i=0;i<m;i++)dp[i][0]=1;
    for(int i=0;i<n;i++)dp[0][i]=1;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size(),n=obstacleGrid[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==1)obstacleGrid[i][j] = -1;
        }
    }

    for(int i=0;i<m;i++){
        if(obstacleGrid[i][0]==-1)break;
        obstacleGrid[i][0]=1;
    }
    for(int i=1;i<n;i++){
        if(obstacleGrid[0][i]==-1)break;    
        obstacleGrid[0][i]=1;
    } 
    
    for(int i=0;i<n;i++){
        cout<<obstacleGrid[0][i]<<" ";
    }
    cout<<"\n";
    
    
    for(int i=1;i<m;i++){
        cout<<obstacleGrid[i][0]<<" ";
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]!=-1){
                if(obstacleGrid[i][j-1]!=-1)obstacleGrid[i][j] +=obstacleGrid[i][j-1]; 
                if(obstacleGrid[i-1][j]!=-1)obstacleGrid[i][j] +=obstacleGrid[i-1][j];
            } 
            cout<<obstacleGrid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return obstacleGrid[m-1][n-1];
}

int main(){
    
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)cin>>grid[i][j];
    
    cout<<uniquePathsWithObstacles(grid)<<"\n";
    return 0;
}