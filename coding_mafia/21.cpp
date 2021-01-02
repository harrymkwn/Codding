#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        int total=0;

        for(auto &x : s){
            if(x=='Q' || x=='R' || x=='O' || x=='P' || x=='A' || x=='D')total++;
            else if(x=='B')total+=2;
        }
        cout<<total<<"\n";
    }
    
    return 0;
}