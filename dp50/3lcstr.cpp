#include<bits/stdc++.h>
using namespace std;

int lcstr(string s1,string s2){
    int n=s1.length(), m= s2.length(),maxlen=0;
    vector<vector<int>> dp(2,vector<int>(m+1,0));
    bool flag=true;
    for(int i=1;i<=n;i++,flag=!flag){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[flag][j] = dp[!flag][j-1] + 1;
                if(dp[flag][j] > maxlen)maxlen = dp[flag][j];
            }
        }
    }

    return maxlen;
}

int main(){
    
    cout<<lcstr("ABACD","CDABA")<<"\n";
    return 0;
}