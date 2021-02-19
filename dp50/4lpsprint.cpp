#include<bits/stdc++.h>
using namespace std;

string lps(string s1,string s2,int i,int j,vector<vector<int>> &lookup){
    if(i==0 || j==0)return "";

    
    if(s1[i-1]==s2[j-1]){
        return lps(s1,s2,i-1,j-1,lookup) + s1[i-1]; 
    }

    if(lookup[i-1][j] > lookup[i][j-1]) return lps(s1,s2,i-1,j,lookup);
    return lps(s1,s2,i,j-1,lookup);

}

int lcs(string s1,string s2,vector<vector<int>> &lookup){
    int n = s1.length();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])lookup[i][j] = lookup[i-1][j-1] + 1;
            else lookup[i][j] = max(lookup[i-1][j],lookup[i][j-1]);
        }
    }

    return lookup[n][n];
}

int main(){
    string s1;
    cin>>s1;
    int n = s1.length();
    string s2=s1;
    reverse(s2.begin(),s2.end());
    vector<vector<int>> lookup(n+1,vector<int>(n+1,0));

    lcs(s1,s2,lookup);
    cout<<lps(s1,s2,n,n,lookup)<<"\n";

    return 0;
}