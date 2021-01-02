#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string x;
        cin>>x;
        string first = x.substr(0,x.length()/2);
        string second = x.substr(x.length()%2==0 ? x.length()/2 : (x.length()/2)+1);
        unordered_map<char,int> mf,ms;
        for(int i=0;i<first.length();i++)mf[first[i]]++;
        for(int i=0;i<second.length();i++)ms[second[i]]++;

        if(mf==ms)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}


//In this type of so^n can use sort also for space optimisation
//and for time optimisation can use 