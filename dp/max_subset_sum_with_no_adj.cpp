#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int find_max(vector<int> arr,int i){
    if(i<0)return 0;
    return max(find_max(arr,i-2)+arr[i],find_max(arr,i-1));
}
//     vector<int> dp(arr.size(),0);
//     dp[0] = arr[0];
//     dp[1] = arr[1];
//     F(2,i+1,j){
//         dp[j] = max(dp[j-2]+arr[j],dp[j-1]);
//     }
//     return dp[i];
// }

int main(){

    vector<int> arr = {75,105,120,75,90,135};

    cout<<find_max(arr,arr.size()-1)<<"\n";
    return 0;
}