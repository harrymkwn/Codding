#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,m=0;
        cin>>x>>y;
        for(int i=1;i<=y;i++){
            int temp = x%i;
            if(m < temp)m=temp;
        }
        cout<<m<<"\n";
    }
    return 0;
}