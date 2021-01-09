#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,j;
        cin>>s>>j;
        unordered_map<char,int> mp;
        int count =0;
        for(auto x : s)mp[x]++;
        for(auto x : j){
            if(mp[x]>0){
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}