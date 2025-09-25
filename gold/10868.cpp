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
#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }
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
vi v, tree;

int init(int node, int v_start, int v_end) {
	if (v_start == v_end) return tree[node] = v[v_start];
	int mid = (v_start + v_end) / 2;
	int left_child = init(node * 2, v_start, mid);
	int right_child = init(node * 2 + 1, mid + 1, v_end);
	return tree[node] = min(left_child, right_child);
}

int find_min(int node, int a, int b, int v_start, int v_end) {
	if (a > v_end || b < v_start) return INF;
	if (a <= v_start && v_end <= b) return tree[node];
	int mid = (v_start + v_end) / 2;
	int left_child = find_min(node * 2, a, b, v_start, mid);
	int right_child = find_min(node * 2 + 1, a, b, mid + 1, v_end);
	return min(left_child, right_child);
}

int main() {
	FASTIO;
	cin >> n >> m;
	int tree_height = (int)ceil(log2(n));
	int tree_size = (1 << (tree_height + 1));
	tree.resize(tree_size);
	VINPUT(v, n);
	init(1, 0, n - 1);
	while (m--) {
		int a, b; cin >> a >> b;
		cout << find_min(1, a - 1, b - 1, 0, n - 1) << endl;
	}
}
