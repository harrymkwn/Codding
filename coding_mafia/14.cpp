#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
      int x,ans=0;
      cin>>x;
        while (x)
        {
            ans += x%10;
            x/=10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}