#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
const int MAX_CHAR = 256; 
int countSub(string str) 
{ 
    vector<int> last(MAX_CHAR, -1); 
    int n = str.length(); 
    int dp[n+1]; 
    dp[0] = 1; 
    for (int i=1; i<=n; i++) 
    { 
        dp[i] = (int)((long long)2*dp[i-1]+mod)%mod; 
  
        if (last[str[i-1]] != -1) 
            dp[i] = dp[i] - (dp[last[str[i-1]]]); 
  
        last[str[i-1]] = (i-1); 
    } 
  
    return (dp[n])%mod; 
} 

int main(){
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        cout<<countSub(s)<<"\n";
    }
    
}