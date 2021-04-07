#include<bits/stdc++.h>
using namespace std;

int mostFrequent(vector<int> arr){
    unordered_map<int,int> mp;
    int most=0,val=0;
    for(auto x : arr){
        mp[x]++;
        if(most<mp[x]){most = mp[x];val=x;} 
    }

    for(auto x : mp){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    return val;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<mostFrequent(arr);
    return 0;
}