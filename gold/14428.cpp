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

int init(int node, int a, int b) {
	if (a == b) return tree[node] = a;
	int m = (a + b) / 2;
	int lc = init(node * 2, a, m);
	int rc = init(node * 2 + 1, m + 1, b);
	if (v[lc] <= v[rc]) {
		return tree[node] = lc;
	} else {
		return tree[node] = rc;
	}
}

int find_min(int node, int a, int b, int A, int B) {
	if (b < A || B < a) return n;
	if (A <= a && b <= B) return tree[node];
	int m = (a + b) / 2;
	int lc = find_min(node * 2, a, m, A, B);
	int rc = find_min(node * 2 + 1, m + 1, b, A, B);
	if (v[lc] <= v[rc]) {
		return lc;
	} else {
		return rc;
	}
}

void update(int node, int a, int b, int i, int value) {
	if (i < a || b < i) return ;
	if (a == b) {
		v[i] = value;
		tree[node] = i;
	} else {
		int m = (a + b) / 2;
		update(node * 2, a, m, i, value);
		update(node * 2 + 1, m + 1, b, i, value);
		if (v[tree[node * 2]] <= v[tree[node * 2 + 1]]) {
			tree[node] = tree[node * 2];
		} else {
			tree[node] = tree[node * 2 + 1];
		}
	}
}

int main() {
	FASTIO;
	cin >> n;
	VINPUT(v, n);
	v.PB(INF);
	cin >> m;

	int tree_size = (1 << (((int)ceil(log2(n + 1))) + 1));
	tree.resize(tree_size);
	init(1, 0, n);
	while (m--) {
		int order, a, b; cin >> order >> a >> b;
		if (order == 1) {
			update(1, 0, n, a - 1, b);
		} else {
			cout << find_min(1, 0, n, a - 1, b - 1) + 1 << endl;
		}
	}
}
