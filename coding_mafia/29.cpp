#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++)cin>>a[i];
        int k;
        cin>>k;

        int uj = a[k-1];
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(a[i]==uj){
                cout<<i+1<<"\n";
                break;
            }
        }
    }
    
    return 0;
}