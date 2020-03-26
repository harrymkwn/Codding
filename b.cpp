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
    vector<vector<string>> dp;
    F(0,n,i){
        cin>>x>>y;
        string str="bb";
        F(0,x-2,i)str = "a" + str;
        F(0,y-1,j)next_permutation(str.begin(),str.end());
        cout<<str<<"\n";
    }
    return 0;
}