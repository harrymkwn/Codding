#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,l,r,x;
    cin>>n>>t;
    vector<int> arr(n+1,0);
    while(t--){
        cin>>l>>r>>x;
        if(x==l)arr[r] = l;
        else if(x==r) arr[l] = r;
        else {arr[l]=x;arr[r]=x;}
    }

    for(auto x:arr)
        cout<<x<<"\n";
}