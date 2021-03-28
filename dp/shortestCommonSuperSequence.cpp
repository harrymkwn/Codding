#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s1, string s2) {
    int n =s1.length();
    int m = s2.length();
    cout<<n<<" "<<m<<"\n";
    int dp[n+1][m+1]={0};
    for(int i=0;i<n+1;i++)dp[i][0]=0;
    for(int j=0;j<m+1;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1 ;
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    int i=n,j=m;
    string str = "";
    while(i && j){
        if(s1[i-1]==s2[j-1]){
            str = s1[i-1] + str;
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j-1]){
            str = s2[j-1] + str;
            str = s1[i-1] + str;
            i--;
            j--;
        }else if(dp[i][j]==dp[i-1][j]){
            str = s1[i-1] + str;
            i--;
        }else if(dp[i][j]==dp[i][j-1]){
            str = s2[j-1] + str;
            j--;
        } 
    }
    while (i==0 && j!=0)
    {
        str = s2[j-1] + str;
        j--;
    }
    while (j==0 && i!=0)
    {
        str = s1[i-1] + str;
        i--;
    }    

    return str;
}

int main(){
    
    cout<<shortestCommonSupersequence("herat","yashvee")<<"\n";
    return 0;
}