#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size(),n=matrix[0].size();

    for(int i=m-2;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(0<j<n-1)matrix[i][j] += min(min(matrix[i+1][j-1],matrix[i+1][j+1]),matrix[i+1][j]);
            else if(j==n-1)matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j-1]);
            else if(j==0)matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j+1]);
        }
    }

    int minval=INT_MAX;
    for(int i=0;i<n;i++){
        if(minval> matrix[0][i] )minval=matrix[0][i];
    }

    return minval==INTMAX_MAX ? -1 : minval;
}



int main(){
    
    
    return 0;
}