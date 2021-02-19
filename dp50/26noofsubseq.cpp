#include<bits/stdc++.h>
using namespace std;


int noofsubseq(string s1,string s2){

    int n = s1.length(),m=s2.length();
    vector<vector<int>> dp(2,vector<int>(m+1,0));
    dp[0][0] = 1;
    dp[1][0] = 1;
    bool flag=true;
    for(int i=1;i<=n;i++,flag=!flag){
        for(int j=1;j<=m;j++){
            dp[flag][j] = dp[!flag][j];
            if(s1[i-1]==s2[j-1]){
                dp[flag][j] +=  dp[!flag][j-1];
            }
        }

    }
    return dp[!flag][m];
}

int main(){
    string s1 = "subsequence",s2="sue";
    cout<<noofsubseq(s1,s2)<<"\n";
    return 0;
}