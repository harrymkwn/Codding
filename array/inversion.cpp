#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];


    multiset<int> s;
    int inv=0;
    for(int i=0;i<n;i++){
        
        s.insert(arr[i]);
    
        auto x = s.upper_bound(arr[i]);
    
        int dist = distance(x,s.end());
    
        inv += dist;
    }
    return 0;
}