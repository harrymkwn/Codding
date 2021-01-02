#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s,o;
        cin>>s;
        o = s;
        reverse(s.begin(),s.end());
        if(s.compare(o)==0)cout<<"wins\n";
        else cout<<"loses\n";
    }
    return 0;
}