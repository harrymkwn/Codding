#include<bits/stdc++.h>
using namespace std;

int lensuperseq(string s1,string s2,vector<vector<int>> &lookup){
    int n = s1.length(),m=s2.length();
    for(int i=0;i<=n;i++)lookup[i][0] = i;
    for(int i=0;i<=m;i++)lookup[0][i] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])lookup[i][j] = lookup[i-1][j-1] + 1;
            else lookup[i][j] = min(lookup[i-1][j],lookup[i][j-1]) + 1;
        }
    }

    return lookup[n][m];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length(),m=s2.length();
    vector<vector<int>> lookup(n+1,vector<int>(m+1,0));

    cout<<lensuperseq(s1,s2,lookup)<<"\n";
    

    return 0;
}