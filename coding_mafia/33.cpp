#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k,x;
        cin>>n>>k;
        vector<bool> a(n,false);
        for(int i=0;i<k;i++){
            cin>>x;
            a[x-1] = true;
        }
        vector<vector<int>> res(2,vector<int>());
        bool flag=false;
        for(int i=0;i<n;i++){
            if(!a[i]){
                if(!flag){
                    res[false].push_back(i+1);
                    flag=true;
                }
                else{
                    res[true].push_back(i+1);
                    flag=false;
                }
            }
        }
        for(int i=0;i<res[0].size();i++)cout<<res[0][i]<<" ";
        cout<<"\n";
        for(int i=0;i<res[1].size();i++)cout<<res[1][i]<<" ";
        cout<<"\n";
    }
    
    return 0;
}