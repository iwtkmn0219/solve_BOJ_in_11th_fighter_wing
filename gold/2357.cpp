#include <bits/stdc++.h>
#define endl "\n"
#define INF 2e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define board_condition(row, col, n, m) (row >= 0 && row < n && col >= 0 && col < m)
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REV(x) reverse(x.begin(), x.end())
#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define VINPUT(v, n) REP(i, 0, n) { ll tmp; cin >> tmp; v.PB(tmp); }
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; } cout << endl
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; } cout << endl
#define WATCH(x) cout << #x << " : " << x << endl
#define DEBUG(x) cout << "DB - " << x << endl
#define PRINT(x) cout <<  x << endl
#define NVOUTPUT(x)
#define NV2DOUTPUT(x)
#define NWATCH(x)
#define NDEBUG(x)
#define NPRINT(x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pi;
struct point {
	int x, y;
};

int n, m;
vector<ll> v;
vector<pair<ll, ll>> tree;

pair<ll, ll> init(int node, int start, int end) {
	if (start == end) return tree[node] = {v[start], v[start]};
	int mid = (start + end) / 2;
	pair<ll, ll> left_child = init(node * 2, start, mid);
	pair<ll, ll> right_child = init(node * 2 + 1, mid + 1, end);
	ll minl = min(left_child.F, right_child.F);
	ll maxl = max(left_child.S, right_child.S);
	return tree[node] = {minl, maxl};
}

pair<ll, ll> find_all(int node, int start, int end, int a, int b) {
	if (end < a || b < start) return {INF, 0};
	if (a <= start && end <= b) return tree[node];
	int mid = (start + end) / 2;
	pair<ll, ll> left_child = find_all(node * 2, start, mid, a, b);
	pair<ll, ll> right_chlid = find_all(node * 2 + 1, mid + 1, end, a, b);
	return {min(left_child.F, right_chlid.F), max(left_child.S, right_chlid.S)};
}

int main() {
	FASTIO;
	cin >> n >> m;
	VINPUT(v, n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	init(1, 0, n - 1);
	while (m--) {
		int a, b; cin >> a >> b;
		pair<ll, ll> tmp = find_all(1, 0, n - 1, a - 1, b - 1);
		cout << tmp.F << " " << tmp.S << endl;
	}
}
