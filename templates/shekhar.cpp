#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
int sum=0;
#define arrinp(v) for(auto &i:v) cin>>i,sum+=i;
#define arrout(v) for(auto &i:v) cout<<i<<" ";
#define newline cout<<endl;
#define all(s) (s).begin(),(s).end()
#define dbg(a) cout<<a<<endl;
#define dbg2(a,b) cout<<a<<" "<<b<<endl;
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t(1);
    cin >> t;
    while (t--) {
        sum=0;
        string s;
        cin>>s;
        int n=s.size();
        if(n%2==0){
            string s1=s.substr(0,n/2);sort(all(s1));
            string s2=s.substr(n/2,n);sort(all(s2));
            // dbg2(s1,s2);
            dbg((s1==s2?"YES":"NO"));
        }
        else{
            string s1=s.substr(0,(int)n/2);sort(all(s1));
            string s2=s.substr((int)n/2+1,n);sort(all(s2));
            // dbg2(s1,s2);
            dbg((s1==s2?"YES":"NO"));
        }
    }
    return 0;
}