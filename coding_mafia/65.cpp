#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n,0);
        cin>>arr;
        sort(arr.begin(),arr.end());
        int ksum=0;
        for(int i=0;i<k;i++)ksum+=arr[i];

        int sum = accumulate(arr.begin(),arr.end(),0);
        cout << abs(sum - ksum*2)<<"\n";
    }
    return 0;
}