#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n,0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        int minn = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] < minn)
                minn = a[i] - a[i - 1];
        }
        cout << minn << "\n";
    }
    return 0;
}