#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,k,n;
        cin>>x>>y>>k>>n;
        vector<vector<int>> a(n,vector<int>(2,0));
        for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
        x-=y;
        int flag=false;
        for(int i=0;i<n && !flag;i++){
            if(x<=a[i][0] and k>=a[i][1])flag=true;
        }
        if(flag)cout<<"LuckyChef\n";
        else cout<<"UnluckyChef\n";
    }
    return 0;
}