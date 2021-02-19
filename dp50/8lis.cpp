#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}

int lis(vector<int> arr,vector<int> &dp,vector<int> &vertex){
    int n = arr.size();
    vertex.resize(n,-1);
    dp.resize(n,0);
    dp[0]=1;
    for(int i=1;i<n;i++){
        int maxc=0,k=0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[j]>maxc){maxc = dp[j];k=j;}
        }
        dp[i] =++maxc;
        if(maxc!=1)vertex[i] = k;
    }

    int liss=0,ind;
    for(int i=0;i<n;i++){
        if(liss<dp[i]){
            liss = dp[i];
            ind = i;
        }
    }
    
    while(vertex[ind]!=-1){
        cout<<arr[ind]<<" ";
        ind = vertex[ind];
    }
    cout<<arr[ind]<<"\n";
    return liss;
}

int main(){
    vector<int> arr,vertex,dp;
    int n;
    cin>>n;
    arr.resize(n,0);
    for(int i=0;i<n;i++){cin>>arr[i];cout<<arr[i]<<"\n";}

    cout<<lis(arr,dp,vertex)<<"\n";
    return 0;
}