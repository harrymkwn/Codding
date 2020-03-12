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
    string abc;
    cin >> abc;
    cout << shash(abc);
    return 0;
}