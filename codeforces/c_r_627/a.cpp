#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int main(){
    int n;
    cin>>n;
    int x,y;
    bool flag,flag2;
    F(0,n,i){
        cin>>x;
        flag2=true;
        cin>>y;
        flag = y%2? true:false;
        F(1,x,j){
            cin>>y;
            if(flag != y%2?true:false){
                flag2 = false;
            }
        }
        if(flag2)cout<<"YES"<<"\n";
        else cout<<"NO\n";
    }
  return 0;
}