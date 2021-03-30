#include<bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(),n=dungeon[0].size();

    for(int i = m-2;i>=0;i--)dungeon[i][n-1] += dungeon[i+1][n-1];
    for(int i = n-2;i>=0;i--)dungeon[m-1][i] += dungeon[m-1][i+1];
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dungeon[i][j] = min(dungeon[i+1][j],dungeon[i][j+1]);
        }
    } 
        
    return dungeon[0][0];       
}

int main(){
    
    return 0;
}