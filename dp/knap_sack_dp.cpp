#include<bits/stdc++.h>
using namespace std;

int knapsnake(int* weight,int * values,int maxWeight , int n,int** dp){

    if(maxWeight==0 || n==0)
        return 0;

    if(!dp[n-1][maxWeight-weight[n-1]])
        dp[n-1][maxWeight-weight[n-1]] = values[n-1] + knapsnake(weight,values,maxWeight-weight[n-1],n-1,dp);
    if(!dp[n-1][maxWeight])
        dp[n-1][maxWeight] = knapsnake(weight,values,maxWeight,n-1,dp);
    return max(dp[n-1][maxWeight-weight[n-1]],dp[n-1][maxWeight]);

}
int main(){
    int n;
    cin>>n;
    int weights[n];
    for(int i=0;i<n;i++)
        cin>>weights[i];
    int values[n];
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    int maxweight=0;
    cin>>maxweight;
    int** dp = new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i] = new int[maxweight+1];
        for(int j=0;j<maxweight;j++)
            dp[i][j]=0;
    }
    cout<<knapsnake(weights,values,maxweight,n,dp);

    for(int i=0;i<n+1;i++)
        delete[]  dp[i];
    delete[] dp;
    return 0;
}