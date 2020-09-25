#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int gcd(int a,int b){
    if(b>a)return gcd(b,a);

    if(b==0)return a;

    return gcd(b,a%b);
}

int main(){
    int x,y;
    while(cin>>x>>y){
        cout<<gcd(x,y)<<"\n";
    }
  return 0;
}