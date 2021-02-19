#include<bits/stdc++.h>
using namespace std;

string editdistance(string s1,string s2,int i,int j,vector<vector<int>> &lookup){
    
    if(i==0)return s2.substr(0,j);
    else if(j==0)return s1.substr(0,i);

    if(s1[i-1]==s2[j-1]){
        return editdistance(s1,s2,i-1,j-1,lookup)+ s1[i-1]; 
    }
    else if(i>0 && (lookup[i-1][j] > lookup[i][j-1])) return editdistance(s1,s2,i-1,j,lookup)+ s1[i-1];
    else if (j>0 && (lookup[i-1][j] <= lookup[i][j-1]))return editdistance(s1,s2,i,j-1,lookup)+ s2[j-1];

    return "";
}

int lcs(string s1,string s2,vector<vector<int>> &lookup){
    int n = s1.length(),m=s2.length();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])lookup[i][j] = lookup[i-1][j-1] + 1;
            else lookup[i][j] = max(lookup[i-1][j],lookup[i][j-1]);
        }
    }

    return lookup[n][m];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length(),m=s2.length();
    vector<vector<int>> lookup(n+1,vector<int>(m+1,0));

    cout<<lcs(s1,s2,lookup)<<"\n";
    cout<<editdistance(s1,s2,n,m,lookup)<<"\n";

    return 0;
}