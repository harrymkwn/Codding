#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    int n;
    string arr;
    vector<map<char, int>> tree;

    void buildtree(int start, int end, int in)
    {
        if (start == end)
        {
            tree[in][arr[start]]=1;
            return;
        }

        int mid = (start + end) >> 1;
        buildtree(start, mid, 2 * in);
        buildtree(mid + 1, end, 2 * in + 1);

        map<char, int> temp = tree[2 * in];

        for (auto x : tree[2 * in + 1])
        {
            temp[x.first] += x.second;
        }

        tree[in] = temp;
    }

    void updateUtils(int start, int end, int in, int ind, char val)
    {

        if (start == ind && end == ind)
        {
            tree[in][arr[ind]]--;
            arr[ind] = val;
            tree[in][val]++;
            return;
        }
        int mid = (start + end) >> 1;

        if (ind <= mid)
            updateUtils(start, mid, 2 * in, ind, val);
        else
            updateUtils(mid + 1, end, 2 * in + 1, ind, val);

        map<char, int> temp = tree[2 * in];

        for (auto x : tree[2 * in + 1])
        {
            temp[x.first] += x.second;
        }

        tree[in] = temp;
    }

    map<char,int> queryUtils(int start, int end, int l, int r, int in)
    {
        if (end < l || start > r){
            map<char,int> temp;
            return temp;
        }

        if (l <= start && end <= r)
            return tree[in];

        int mid = (start + end) >> 1;

        map<char,int> left = queryUtils(start, mid, l, r, 2 * in);
        map<char,int> right = queryUtils(mid + 1, end, l, r, 2 * in + 1);

        for (auto x : right)
        {
            left[x.first] += x.second;
        }
        return  left ;
    }

public:
    SegTree(string str)
    {
        n = str.size();
        arr = str;

        int h = (int)ceil(log2(n));
        int size = 2 * pow(2, h);

        tree.resize(size);

        buildtree(0, n - 1, 1);
    }

    void update(int ind, char val)
    {
        return updateUtils(0, n - 1, 1, ind, val);
    }

    map<char,int> query(int l, int r)
    {
        return queryUtils(0, n - 1, l, r, 1);
    }

    void print_tree()
    {
        int p = 1;
        for (int i = 1; i < tree.size(); i++)
        {
            if (p == i)
            {
                p *= 2;
                cout << "\n";
            }
            cout << tree[i].size() << " ";
        }
        cout<<"\n";
    }
};

int main()
{
    string str;
    cin >> str;
    int t;
    cin >> t;
    int x, y, z;
    char c;
    SegTree obj(str);
    while (t--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y >> c;
            obj.update(y - 1, c);
            // obj.print_tree();
        }
        else if (x == 2)
        {
            cin >> y >> z;
            // obj.print_tree();
            map<char,int> temp = obj.query(y - 1, z - 1);
            int c = 0;
            for(auto x:temp)if(x.second > 0)c++;
            cout<<c << "\n";
        }
    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
	
// 	string s;
// 	cin >> s;
// 	vector<set<int>> poss(26);
// 	for (int i = 0; i < int(s.size()); ++i) {
// 		poss[s[i] - 'a'].insert(i);
// 	}
	
// 	int q;
// 	cin >> q;
// 	for (int i = 0; i < q; ++i) {
// 		int tp;
// 		cin >> tp;
// 		if (tp == 1) {
// 			int pos;
// 			char c;
// 			cin >> pos >> c;
// 			--pos;
// 			poss[s[pos] - 'a'].erase(pos);
// 			s[pos] = c;
// 			poss[s[pos] - 'a'].insert(pos);
// 		} else {
// 			int l, r;
// 			cin >> l >> r;
// 			--l, --r;
// 			int cnt = 0;
// 			for (int c = 0; c < 26; ++c) {
// 				auto it = poss[c].lower_bound(l);
// 				if (it != poss[c].end() && *it <= r) {cnt++;}
// 			}
// 			cout << cnt << endl;
// 		}
// 	}
	
// 	return 0;
// }