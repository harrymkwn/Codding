#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (auto &v : vec)
        is >> v;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << '[';
    for (auto v : vec)
        os << v << ',';
    os << ']' << endl;
    return os;
}

void solve()
{
    int x;
    cin >> x;
    int n;
    cin >> n;

    if (x % 2 == 0){
        bool flag = false;
        while (n>0)
        {   
            flag |= n%2==0;
            n /= 100;
        }
        if(flag)cout<<2<<"\n";
        else cout<<1<<"\n";
    }
    else{
        bool flag = false;
        if(n<10 && n%2==0)cout<<2<<"\n";
        else if(n<10 && n%2==1)cout<<1<<"\n";
        else {
            while (n>0)
            {
                flag |= n%2==1;
                n /= 100;
            }
            if(flag)cout<<2<<"\n";
            else cout<<1<<"\n";
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}