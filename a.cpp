#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int main(){
    int n,x,y;
    cin>>n;
    F(0,n,i){
        cin>>x>>y;
        cout<<(y-x%y)%y<<"\n";
    }
    return 0;
}