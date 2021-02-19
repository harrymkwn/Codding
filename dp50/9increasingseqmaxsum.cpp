#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> arr,vector<int> &sum){
    int n = arr.size();
    sum.resize(n,0);
    sum[0]=arr[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && sum[j]>sum[i])sum[i] = sum[j];
        }
        sum[i] += arr[i];
    }
    int ret=0;
    for(auto x: sum){
        if(x>ret)ret=x;
    }

    return ret;
}

int main(){
    int n;
    vector<int> arr,dp;
    cin>>n;
    arr.resize(n,0);
    for(int i=0;i<n;i++){cin>>arr[i];cout<<arr[i]<<"\n";}

    cout<<lis(arr,dp)<<"\n";
    return 0;
}