#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 +7;
 
#define FILE_IO   freopen("in.txt","r",stdin);
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);
#define TEST(t) int t; cin>>t; while(t--)
 
 
#define f(i,a,b) for(int (i)=a;(i)<b;(i)++)
#define rep(s,n) for(int i=s;i<n;i++)
#define rep2(s,n) for(int j=s;j<n;j++)
#define rep1(s,n) for(int i=s;i<=n;i++)
#define repr(s,n) for(int i=n;i>=s;i--)
#define disp(a,n) for(int *it=a;it<(a+n);it++) cout<<*it<<" "; cout<<endl;
#define deb(a,b) cout<<a<<"= "<<b<<endl;
 
 
#define int int64_t
#define ll long long int
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100045
 
vector <int> Fac(N,0);
 
void fact(int n)
{
    rep(1,n)
    {
        //cout<<i<<endl;
        Fac[i]=(Fac[i-1]*i)%MOD;
    }
}
int power(int x,int y)
{
    int res=1;
    x=x%MOD;
    while(y>0)
    {
        if(y&1)
            res=(res*x)%MOD;
        y=y>>1;
        x=(x*x)%MOD;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    int ans =0;
    int cnt[n/4+1]={0},x;
    //deb("n",n);
    repr(1,n/4)
    {
        x=n/i;
        //cout<<i<<" ";
        int dem_inv=power(Fac[4]*Fac[x-4],MOD-2);
        cnt[i]=(Fac[x]*dem_inv)%MOD;
        for(int j=2*i;j<=n/4;j+=i){
            //deb("j",j);
            cnt[i]=(cnt[i]-cnt[j]+MOD)%MOD;
        }
        //cout<<cnt[i]<<endl;
        ans=(ans +power(i,4) * cnt[i])%MOD;
    }
    //deb("ans",ans);
    cout<<ans<<endl;
}
signed main()
{
    FASTIO
    #ifndef ONLINE_JUDGE
    FILE_IO
    #endif
    Fac[0]=1;
    fact(100005);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}