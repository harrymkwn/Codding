#define main fakemain
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " : " << x << "\n";
#define debug(x, y) cerr << #x << " : " << x << "\t" << #y << " : " << y << "\n";
#define N 1010
#else
#define deb(x)
#define debug(x, y)
#define N 100010
#endif

#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define setp(n) cout << fixed << setprecision(n)
#define mset(x, y) memset(x, y, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define checkbit(x, i) (x & (1ll << i)) ? 1 : 0
#define setbit(x, i) x | (1ll << i)
#define compbit(x, i) x ^ (1ll << i)
#define ff first
#define ss second
#define mod 1000000007

template <class T>
T complement(T x)
{
    T ans = 0;
    T temp = 1;
    while (x)
    {
        ans += ((x % 2) ? 0 : 1) * temp;
        x >>= 1;
        temp <<= 1;
    }
    return ans;
}

ll pow_mod(ll x, ll y)
{
    ll r = 1;
    for (; y; y >>= 1, x = (ll)x * x % mod)
        if (y & 1)
            r = (ll)r * x % mod;
    return r;
}

void main()
{
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
#endif
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt0 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                cnt0++;
        }

        if (cnt0 % 2 || s[0] != '1' || s[n - 1] != '1')
        {
            cout << "NO\n";
            continue;
        }

        vector<char> a(n), b(n);

        a[0] = '(';
        b[0] = '(';
        a[n - 1] = ')';
        b[n - 1] = ')';

        bool f = 1;
        bool d = 1;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '1')
            {
                if (f)
                {
                    a[i] = '(';
                    b[i] = '(';
                }
                else
                {
                    a[i] = ')';
                    b[i] = ')';
                }

                f = !f;
            }
            else
            {
                if (d)
                {
                    a[i] = '(';
                    b[i] = ')';
                }
                else
                {
                    a[i] = ')';
                    b[i] = '(';
                }

                d = !d;
            }
        }

        cout << "YES\n";

        for (char &c : a)
            cout << c;

        cout << "\n";

        for (char &c : b)
            cout << c;

        cout << "\n";
    }
}
#undef main
#ifndef ONLINE_JUDGE
void rmv_()
{
    remove("IN_TEMP_A_F6ZzbIN");
    remove("OUT_TEMP_A_F6ZzbIN");
}
string to_str__booster__(int x)
{
    char buf[100];
    sprintf(buf, "%d", x);
    return buf;
}
vector<string> clean__booster___(string u)
{
    u.push_back('\n');
    vector<string> w;
    string c;
    for (auto t : u)
    {
        if (t == '\n' || t == '\r')
        {
            while (c.size() && c.back() == ' ')
                c.pop_back();
            if (c.size())
                w.push_back(c);
            c.clear();
        }
        else
            c.push_back(t);
    }
    return w;
}
int to_num__booster__(string s)
{
    int w = atoi(s.c_str());
    char buf[10];
    sprintf(buf, "%d", w);
    if (buf == s)
        return w;
    return -1;
}
int main(int argc, char **argv)
{
    vector<string> code;
    {
        std::ifstream t(__FILE__);
        std::stringstream buffer;
        buffer << t.rdbuf();
        t.close();
        code = clean__booster___(buffer.str());
    }
    int num_samples = 0;
    map<pair<int, int>, string> samples;
    {
        string cs = "";
        pair<int, int> id(-1, -1);
        for (auto s : code)
        {
            if (s.substr(0, 4) == "*o* ")
            {
                if (id.second != -1)
                    samples[id] = cs;
                id = make_pair(-1, -1), cs = "";
                string g = s.substr(4);
                string si = "Sample Input ";
                string so = "Sample Output ";
                if (g.back() == ':' && g.substr(0, si.size()) == si)
                {
                    int w = to_num__booster__(g.substr(si.size(), g.size() - si.size() - 1));
                    if (w >= 1)
                        id = make_pair(w, 0);
                }
                if (g.back() == ':' && g.substr(0, so.size()) == so)
                {
                    int w = to_num__booster__(g.substr(so.size(), g.size() - so.size() - 1));
                    if (w >= 1)
                        id = make_pair(w, 1);
                }
            }
            else
                cs = cs + s + "\n";
        }
        while (samples.count(make_pair(num_samples + 1, 0)) && samples.count(make_pair(num_samples + 1, 1)))
            ++num_samples;
    }
    if (!num_samples)
    {
        fakemain();
        return 0;
    }
    int w;
    int cap = 1, sil = 0;
    if (argc == 2)
    {
        w = to_num__booster__(argv[1]);
        cerr << w << "... ";
        cap = 2;
    }
    else
    {
        cerr << num_samples << " samples. autofeed: ";
        cerr.flush();
        string u;
        getline(cin, u);
        if (u == "a")
        {
            cerr << "testing all samples..." << endl;
            for (int i = 1; i <= num_samples; ++i)
            {
                cerr << "testing sample ";
                int rt = system(((string) "\"" + argv[0] + "\" " + to_str__booster__(i)).c_str());
                if (rt)
                    cerr << endl
                         << "WA/RE (return value " << rt << ")\n",
                        exit(-1);
            }
            cerr << "all samples passed!" << endl;
            exit(0);
        }
        while (1)
        {
            if (u.size() && u.back() == 'r')
                u.pop_back(), cap = 0;
            else if (u.size() && u.back() == 's')
                u.pop_back(), sil = 1, cap = 0;
            else
                break;
        }
        w = to_num__booster__(u);
    }
    string in, out;
    rmv_();
    if (w >= 1 && w <= num_samples)
    {
        in = samples[make_pair(w, 0)];
        out = samples[make_pair(w, 1)];
        ofstream o("IN_TEMP_A_F6ZzbIN");
        o << in;
        o.close();
        freopen("IN_TEMP_A_F6ZzbIN", "r", stdin);
        if (cap)
        {
            if (cap != 2)
                cerr << "============= testcase " << w << " (captured) =============" << endl;
            freopen("OUT_TEMP_A_F6ZzbIN", "w", stdout);
        }
        else
        {
            cerr << "================== testcase " << w << " ===================" << endl;
        }
    }
    else
    {
        cap = 0;
        cerr << "=============== normal run ================" << endl;
    }
    time_t start_time = clock();
    fakemain();
    time_t end_time = clock();
    bool force_stop = false;
    if (w >= 1 && w <= num_samples)
    {
        string out_str;
        if (cap)
        {
            fclose(stdout);
            std::ifstream t("OUT_TEMP_A_F6ZzbIN");
            std::stringstream buffer;
            buffer << t.rdbuf();
            t.close();
            out_str = buffer.str();
            if (cap != 2)
                cerr << out_str;
        }
        if (sil)
            ;
        else
        {
            if (cap != 2)
                cerr << endl
                     << "=================================================" << endl
                     << "sample output:" << endl
                     << out << endl;
            if (cap)
            {
                if (clean__booster___(out) == clean__booster___(out_str))
                    cerr << "compare passed (" << int((end_time - start_time) * 1000.0 / CLOCKS_PER_SEC + 0.5) << "ms)!" << endl;
                else
                {
                    cerr << "compare failed (" << int((end_time - start_time) * 1000.0 / CLOCKS_PER_SEC + 0.5) << "ms)!" << endl;
                    force_stop = true;
                    if (cap == 2)
                    {
                        cerr << "=============== your output ===============" << endl
                             << out_str << endl
                             << "============== sample output ==============" << endl
                             << out << endl;
                    }
                }
            }
        }
    }
    fclose(stdin);
    rmv_();
    if (force_stop)
        exit(-1);
}
#else
int main()
{
    fakemain();
}
#endif
/*
*o* Sample Input 1:
3
6
101101
10
1001101101
4
1100
*o* Sample Output 1:
YES
()()()
((()))
YES
()()((()))
(())()()()
NO
*o* -Raj Detroja 
*/