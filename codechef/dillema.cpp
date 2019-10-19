#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t=0;
    cin>>t;
    string s;
    while (t--){
    cin>>s;
    int count =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')count++;
    }

    if(count&1==0)cout<<"WIN\n";
    else cout<<"LOSE\n";
    }
}