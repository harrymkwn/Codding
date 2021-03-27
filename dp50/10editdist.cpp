#include<bits/stdc++.h>
using namespace std;


int lcs(string s1,string s2,vector<vectorn<int>> &lookup){
    int m = s1.length(),n=s2.length();
    for(int i=0;i<=m;i++)lookup[i][0]=i;
    for(int i=0;i<=n;i++)lookup[0][i]=i;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int editdist =0;
            if(s1[i-1]!=s2[j-1])editdist++;
            
            lookup[i][j] = min(min(lookup[i-1][j]+1,lookup[i][j-1]+1),lookup[i-1][j-1]+editdist);
        }
    }

    return lookup[m][n];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.length(),n=s2.length();
    vector<vector<int>> lookup(m+1,vector<int>(n+1,0));

    cout<<lcs(s1,s2,lookup)<<"\n";

    return 0;
}