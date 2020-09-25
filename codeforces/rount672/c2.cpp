// #include <algorithm>
// #include <array>
// #include <cassert>
// #include <cstring>
// #include <iostream>
// #include <vector>
// using namespace std;
 
// template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
// template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
// #ifdef NEAL_DEBUG
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif
 
// const int64_t INF64 = int64_t(2e18) + 5;
 
// struct segment {
//     int64_t dp[2][2];
 
//     segment(int number = 0) {
//         dp[0][0] = -number;
//         dp[1][1] = number;
//         dp[0][1] = dp[1][0] = -INF64;
//     }
 
//     bool empty() const {
//         return dp[1][1] <= 0;
//     }
 
//     void join(const segment &other) {
//         if (empty()) {
//             *this = other;
//             return;
//         } else if (other.empty()) {
//             return;
//         }
 
//         int64_t next_dp[2][2];
 
//         for (int a = 0; a < 2; a++)
//             for (int b = 0; b < 2; b++)
//                 next_dp[a][b] = max(dp[a][b], other.dp[a][b]);
 
//         for (int a = 0; a < 2; a++)
//             for (int b = 0; b < 2; b++)
//                 for (int c = 0; c < 2; c++)
//                     next_dp[a][c] = max(next_dp[a][c], dp[a][b] + other.dp[!b][c]);
 
//         memcpy(dp, next_dp, sizeof(dp));
//     }
 
//     void join(const segment &a, const segment &b) {
//         *this = a;
//         join(b);
//     }
// };
 
// int right_half[32];
 
// struct basic_seg_tree {
//     static const bool POWER_OF_TWO_MODE = true;
 
//     int tree_n = 0;
//     vector<segment> tree;
 
//     basic_seg_tree(int n = -1) {
//         if (n >= 0)
//             init(n);
//     }
 
//     void init(int n) {
//         if (POWER_OF_TWO_MODE) {
//             tree_n = 1;
 
//             while (tree_n < n)
//                 tree_n *= 2;
//         } else {
//             tree_n = n;
//         }
 
//         tree.assign(2 * tree_n, segment());
//     }
 
//     // Builds our tree from an array in O(n).
//     void build(const vector<segment> &initial) {
//         int n = int(initial.size());
//         init(n);
//         assert(n <= tree_n);
 
//         for (int i = 0; i < n; i++)
//             tree[tree_n + i] = initial[i];
 
//         for (int position = tree_n - 1; position > 0; position--)
//             tree[position].join(tree[2 * position], tree[2 * position + 1]);
//     }
 
//     segment query(int a, int b) const {
//         assert(0 <= a && a <= b && b <= tree_n);
//         segment answer;
//         int r_size = 0;
 
//         for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
//             if (a & 1)
//                 answer.join(tree[a++]);
 
//             if (b & 1)
//                 right_half[r_size++] = --b;
//         }
 
//         for (int i = r_size - 1; i >= 0; i--)
//             answer.join(tree[right_half[i]]);
 
//         return answer;
//     }
 
//     segment query_single(int index) const {
//         assert(0 <= index && index < tree_n);
//         return tree[tree_n + index];
//     }
 
//     void join_up(int position) {
//         while (position > 1) {
//             position /= 2;
//             tree[position].join(tree[2 * position], tree[2 * position + 1]);
//         }
//     }
 
//     void update(int index, const segment &seg) {
//         assert(0 <= index && index < tree_n);
//         int position = tree_n + index;
//         tree[position] = seg;
//         join_up(position);
//     }
// };
 
 
// void run_case() {
//     int N, Q;
//     cin >> N >> Q;
//     vector<int> A(N);
//     basic_seg_tree tree(N);
//     vector<segment> initial(N);
 
//     for (int i = 0; i < N; i++) {
//         cin >> A[i];
//         initial[i] = segment(A[i]);
//     }
 
//     tree.build(initial);
//     cout << tree.tree[1].dp[1][1] << '\n';
 
//     for (int q = 0; q < Q; q++) {
//         int L, R;
//         cin >> L >> R;
//         L--; R--;
//         tree.update(L, segment(A[R]));
//         tree.update(R, segment(A[L]));
//         swap(A[L], A[R]);
//         cout << tree.tree[1].dp[1][1] << '\n';
//     }
// }
 
// int main() {
//     ios::sync_with_stdio(false);
// #ifndef NEAL_DEBUG
//     cin.tie(nullptr);
// #endif
 
//     int tests;
//     cin >> tests;
 
//     while (tests-- > 0)
//         run_case();
// }

// #include <iostream>
// #include <vector>
// #include <chrono>
// #include <random>
// #include <cassert>
 
// std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
 
// #define int long long
// const long long INF = 1e18;
// struct Node {
// 	Node(int v = -1) {
// 		// init
// 		mx[0] = mn[0] = 0;
// 		mx[1] = mn[1] = v;
// 	}
	
// 	Node(Node l, Node r) {
// 		// merge
// 		if(l.mx[1] == -1) {
// 			*this = r;
// 		} else if(r.mx[1] == -1) {
// 			*this = l;
// 		} else {
// 			for(int i = 0; i < 2; i++) {
// 				mn[i] = INF;
// 				mx[i] = -INF;
// 			}
// 			for(int i = 0; i < 2; i++) {
// 				for(int j = 0; j < 2; j++) {
// 					mn[i^j] = std::min(mn[i^j], l.mn[i] + (i == 1 ? -r.mx[j] : r.mn[j]));
// 					mx[i^j] = std::max(mx[i^j], l.mx[i] + (i == 1 ? -r.mn[j] : r.mx[j]));
// 				}
// 			}
// 		}
// 	}
 
// 	int ans() { return std::max(mx[0], mx[1]); }
 
// 	// atributes
// 	int mn[2], mx[2];
// };
 
// template <class i_t, class e_t>
// class SegmentTree {
// public:
// 	void init(std::vector<e_t> base) {
// 		n = base.size();
// 		tree.resize(2 * n);
// 		for(int i = 0; i < n; i++) {
// 			tree[i + n] = i_t(base[i]);
// 		}
// 		for(int i = n - 1; i > 0; i--) {
// 			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
// 		}
// 	}
	
// 	i_t qry(int l, int r) {
// 		i_t lp, rp;
// 		for(l += n, r += n; l < r; l /= 2, r /= 2) {
// 			if(l & 1) lp = i_t(lp, tree[l++]);
// 			if(r & 1) rp = i_t(tree[--r], rp);
// 		}
// 		return i_t(lp, rp);
// 	}
	
// 	void upd(int pos, e_t v) {
// 		pos += n;
// 		tree[pos] = i_t(v);
// 		for(pos /= 2; pos > 0; pos /= 2) {
// 			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
// 		}
// 	}
	
// private:
// 	int n;
// 	std::vector<i_t> tree;
// };
 
 
// int32_t main() {
// 	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
// 	int t;
// 	std::cin >> t;
// 	while(t--) {
// 		int n, q;
// 		std::cin >> n >> q;
// 		std::vector<int> a(n);
// 		for(int i = 0; i < n; i++) {
// 			std::cin >> a[i];
// 		}
// 		SegmentTree<Node, int> tree;
// 		tree.init(a);
// 		std::cout << tree.qry(0, n).ans() << '\n';
// 		while(q--) {
// 			int l, r;
// 			std::cin >> l >> r;
// 			l--;r--;
// 			std::swap(a[l], a[r]);
// 			tree.upd(l, a[l]);
// 			tree.upd(r, a[r]);
// 			std::cout << tree.qry(0, n).ans() << '\n';
// 		}
// 	}
// }


// #include <bits/stdc++.h>
// using namespace std;
// using lint = long long;
// using pint = pair<int, int>;
// using plint = pair<lint, lint>;
// struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
// #define ALL(x) (x).begin(), (x).end()
// #define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
// #define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
// #define REP(i, n) FOR(i,0,n)
// #define IREP(i, n) IFOR(i,0,n)
// template <typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
// template <typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
// template <typename V, typename T> void ndfill(V &x, const T &val) { x = val; }
// template <typename V, typename T> void ndfill(vector<V> &vec, const T &val) { for (auto &v : vec) ndfill(v, val); }
// template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
// template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
// template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
// template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
// template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
// template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
// template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
// #if __cplusplus >= 201703L
// template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
// template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
// #endif
// template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
// template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
// template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
// template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
// template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
// template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
// template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
// template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
// #ifdef HITONANODE_LOCAL
// #define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
// #else
// #define dbg(x)
// #endif
 
// // Nonrecursive Segment Tree (point-update, range-get)
// // - Conditions for operations:
// //   - merge_data: [TDATA, TDATA] -> TDATA, e(x, y) == e(y, x)
// //   - data2ret: [TDATA, TQUERY] -> TRET
// //   - merge_ret: [TRET, TRET] -> TRET, g(defaultRET, x) == x, g(x, y) = g(y, x)
// //   - commutability f(e(x, y), q) == g(f(x, q), f(y, q))
// template <typename TDATA, typename TRET, typename TQUERY>
// struct NonrecursiveSegmentTree
// {
//     int N;
//     TRET defaultRET;
//     virtual TDATA merge_data(const TDATA &, const TDATA &) = 0;
//     virtual TRET data2ret(const TDATA &, const TQUERY &) = 0;
//     virtual TRET merge_ret(const TRET &, const TRET &) = 0;
//     std::vector<TDATA> data;
//     inline TDATA &at(int i) { return data[i]; }
 
//     inline void _merge(int i) { at(i) = merge_data(at(i << 1), at((i << 1) + 1)); }
//     void initialize(const std::vector<TDATA> &seq, TRET RET_ZERO) {
//         N = seq.size();
//         defaultRET = RET_ZERO;
//         data = seq;
//         data.insert(data.end(), seq.begin(), seq.end());
//         for (int i = N - 1; i; i--) _merge(i);
//     }
//     NonrecursiveSegmentTree() = default;
//     void update(int pos, const TDATA &x) {
//         assert(pos >= 0 and pos < N);
//         at(pos + N) = x;
//         for (int i = pos + N; i > 1;) i >>= 1, _merge(i);
//     }
 
//     // [l, r), 0-indexed
//     TRET get(int l, int r, TQUERY query = NULL) {
//         assert(l >= 0 and r <= N);
//         TRET retl = defaultRET, retr = defaultRET;
//         l += N, r += N;
//         while (l < r) {
//             if (l & 1) retl = merge_ret(retl, data2ret(data[l++], query));
//             if (r & 1) retr = merge_ret(data2ret(data[--r], query), retr);
//             l >>= 1, r >>= 1;
//         }
//         return merge_ret(retl, retr);
//     }
 
//     // Calculate smallest r that satisfies condition(g(f(x_l, q), ..., f(x_{r - 1}, q)) == true
//     // Assumption: Monotonicity of g(x_l, ..., x_r) about r (l: fixed)
//     // Complexity: O(log N)
//     int binary_search(int l, auto condition, TQUERY query = NULL) {
//         std::stack<int> rs;
//         l += N;
//         int r = N * 2;
//         TRET retl = defaultRET;
//         if (condition(retl)) return l - N;
//         while (l < r) {
//             if (l & 1) {
//                 TRET ret_tmp = merge_ret(retl, data2ret(data[l], query));
//                 if (condition(ret_tmp)) {
//                     while (l * 2 < N * 2) {
//                         ret_tmp = merge_ret(retl, data2ret(data[l * 2], query));
//                         if (condition(ret_tmp)) l *= 2;
//                         else retl = ret_tmp, l = l * 2 + 1;
//                     }
//                     return l - N;
//                 }
//                 l++;
//                 retl = ret_tmp;
//             }
//             if (r & 1) rs.push(--r);
//             l >>= 1, r >>= 1;
//         }
//         while (!rs.empty()) {
//             l = rs.top();
//             rs.pop();
//             TRET ret_tmp = merge_ret(retl, data2ret(data[l], query));
//             if (condition(ret_tmp)) {
//                 while (l * 2 < N * 2) {
//                     ret_tmp = merge_ret(retl, data2ret(data[l * 2], query));
//                     if (condition(ret_tmp)) l *= 2;
//                     else retl = ret_tmp, l = l * 2 + 1;
//                 }
//                 return l - N;
//             }
//             retl = ret_tmp;
//         }
//         return N;
//     }
 
//     template <typename T1, typename T2, typename T3>
//     friend std::ostream &operator<<(std::ostream &os, NonrecursiveSegmentTree<T1, T2, T3> s)
//     {
//         os << "[SegmentTree (len: " << s.N << ')';
//         for (int i = 0; i < s.N; i++) os << s.at(i + s.N) << ',';
//         os << "]";
//         return os;
//     }
// };
 
 
// // Range Minimum Query
// // - get: return min(x_l, ..., x_{r - 1})
 
// constexpr lint INF = 1e18;
// struct T
// {
//     array<lint, 4> a;
//     T() = default;
//     T(lint v) {
//         a[0] = a[3] = 0;
//         a[1] = v;
//         a[2] = -v;
//     }
// };
 
// T merge(const T &l, const T &r)
// {
//     T ret = l;
//     REP(i, 4) REP(j, 4) if (i % 2 == j / 2)
//     {
//         chmax(ret.a[i / 2 * 2 + j % 2], l.a[i] + r.a[j]);
//     }
//     return ret;
// }
// struct ST : public NonrecursiveSegmentTree<T, T, bool>
// {
//     using SegTree = NonrecursiveSegmentTree<T, T, bool>;
//     T merge_data(const T &vl, const T &vr) override { return merge(vl, vr); };
//     T data2ret(const T &v, const bool &q) override { return v; }
//     T merge_ret(const T &vl, const T &vr) override { return merge(vl, vr); };
//     ST(const std::vector<T> &seq, T defaultmin) : SegTree::NonrecursiveSegmentTree() {
//         SegTree::initialize(seq, defaultmin);
//     };
// };
 
 
// void solve()
// {
//     int N, Q;
//     cin >> N >> Q;
//     vector<lint> A(N);
//     cin >> A;
 
//     vector<T> v(N);
//     REP(i, N) v[i] = T(A[i]);
//     ST tree(v, T());
 
//     cout << tree.get(0, N).a[1] << '\n';
//     while (Q--)
//     {
//         int l, r;
//         cin >> l >> r;
//         l--, r--;
//         swap(v[l], v[r]);
//         tree.update(l, v[l]);
//         tree.update(r, v[r]);
//         cout << tree.get(0, N).a[1] << '\n';
//     }
// }
// int main()
// {
//     int T;
//     cin >> T;
//     while (T--) solve();


// #include <bits/stdc++.h>
 
// #define mp make_pair
// #define mt make_tuple
// #define fi first
// #define se second
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define forn(i, n) for (int i = 0; i < (int)(n); ++i)
// #define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// #define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
// #define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
 
// using namespace std;
 
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// typedef vector<pii> vpi;
// typedef vector<vi> vvi;
// typedef long long i64;
// typedef vector<i64> vi64;
// typedef vector<vi64> vvi64;
// typedef pair<i64, i64> pi64;
// typedef double ld;
 
// template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
// template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
// struct TNode {
//     int L, R;
//     int l, r;
//     i64 ans[2][2];
// };
 
// const int maxn = 310000;
// int a[maxn];
// TNode t[2 * maxn];
// int tc = 0;
 
// #define dn TNode &n = t[node]
 
// void relax(int node) {
//     dn;
//     forn(x, 2) forn(y, 2) n.ans[x][y] = max(t[n.l].ans[x][y], t[n.r].ans[x][y]);
//     forn(x, 2) forn(y, 2) forn(z, 2) uax(n.ans[x][z], t[n.l].ans[x][y] + t[n.r].ans[y ^ 1][z]);
// }
 
// int buildTree(int L, int R) {
//     int node = tc++;
//     dn;
//     n = {L, R, -1, -1, {{-(i64)1e18, -(i64)1e18}, {-(i64)1e18, -(i64)1e18}}};
//     if (R - L == 1) {
//         n.ans[0][0] = a[L];
//         n.ans[1][1] = -a[L];
//     } else {
//         int M = (L + R) / 2;
//         n.l = buildTree(L, M);
//         n.r = buildTree(M, R);
//         relax(node);
//     }
//     return node;
// }
 
// void change(int node, int i, int x) {
//     dn;
//     if (i < n.L || i >= n.R) return;
//     if (n.R - n.L == 1) {
//         n.ans[0][0] = x;
//         n.ans[1][1] = -x;
//         return;
//     }
//     change(n.l, i, x);
//     change(n.r, i, x);
//     relax(node);
// }
 
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.precision(10);
//     cout << fixed;
// #ifdef LOCAL_DEFINE
//     freopen("input.txt", "rt", stdin);
// #endif
 
//     int T;
//     cin >> T;
//     while (T--) {
//         int n, q;
//         cin >> n >> q;
//         forn(i, n) cin >> a[i];
//         tc = 0;
//         int root = buildTree(0, n);
//         cout << max(t[root].ans[0][0], t[root].ans[0][1]) << '\n';
//         while (q--) {
//             int x, y;
//             cin >> x >> y;
//             --x; --y;
//             swap(a[x], a[y]);
//             change(root, x, a[x]);
//             change(root, y, a[y]);
//             cout << max(t[root].ans[0][0], t[root].ans[0][1]) << '\n';
//         }
//     }
 
// #ifdef LOCAL_DEFINE
//     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
// #endif
//     return 0;
// }