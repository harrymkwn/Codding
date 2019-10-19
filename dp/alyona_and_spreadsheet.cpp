#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    int dp[n+1][m+1]={0};
    for(int j=1;j<=m;j++){
        dp[1][1]=1;
        for(int i=2;i<=n;i++)
            if(arr[i-1][j-1]>=arr[i-2][j-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = i;            
    }

    int q;
    cin>>q;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        bool flag=false;
        for(int j=1;j<=m;j++)
            if(x>=dp[y][j])
                flag=true;

        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}