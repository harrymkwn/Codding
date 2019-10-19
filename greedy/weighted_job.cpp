#include<bits/stdc++.h>
using namespace std;

struct job
{
    int start,finish,profit;
};

bool filter(job a,job b){
    if(a.finish!=b.finish)
        return a.finish<b.finish;
    return a.start<b.start;
}


int main(){
    int n;
    cin>>n;
    
    job* arr = new job[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    sort(arr,arr+n,filter);

    int* dp = new int[n];
    dp[0]=arr[0].profit;
    int tot_max=dp[0];
    for(int i=1;i<n;i++){
        int including = arr[i].profit;
        int lnconflict =-1;
        for(int j=i-1;j>=0;j--){
            if(arr[i].start>=arr[j].finish){
                lnconflict=j;
                break;
            }
        }
        if(lnconflict!=1)
            including += dp[lnconflict];    
    dp[i] = max(including,dp[i-1]);

    }
    cout<<dp[n-1];
    delete[] arr;
    delete[] dp;
}