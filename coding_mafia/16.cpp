#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    int ans  = x-y;
    int last = ans%10;
    if(0<=last<9)ans++;
    else ans--;
    cout<<ans<<"\n";
    return 0;
}