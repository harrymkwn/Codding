#include<bits/stdc++.h>
using namespace std;

int sq(int x){
    return pow(x,2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x1,x2,x3,y1,y2,y3;
        cin>>n;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        int count=0;
        sqrt(sq(x1-x2)+sq(y1-y2))<=n ? count++ : 0; 
        sqrt(sq(x2-x3)+sq(y2-y3))<=n ? count++ : 0; 
        sqrt(sq(x3-x1)+sq(y3-y1))<=n ? count++ : 0;
        if(count>1)cout<<"yes\n";
        else cout<<"no\n"; 
    }
    return 0;
}