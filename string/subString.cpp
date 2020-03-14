#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

ll shash(string const &str)
{
    ll p = 31;
    ll hvalue = 0;
    ll mul = 1;
    F(0, str.size(), i)
    {
        hvalue = (hvalue + ((str[i] - 'a' + 1) * mul) % m) % m;
        mul = (mul * p) % m;
    }

    return hvalue;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<string, ll>> s(n);
    F(0, n, i)
    {
        cin >> s[i].first;
        s[i].second = shash(s[i].first);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int main(){

  return 0;
}