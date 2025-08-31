#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
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

int n, s;
vi v;
vi tree;

int init(vi &arr, vi &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left = init(arr, tree, node * 2, start, mid);
	int right = init(arr, tree, node * 2 + 1, mid + 1, end);
	tree[node] = left + right;
	return tree[node];
}

int seg_sum(vi &tree, int node, int start, int end, int left, int right) {
	if (end < left || start > right) return 0;
	if (end <= right && start >= left) return tree[node];
	int mid = (start + end) / 2;
	int left_child = seg_sum(tree, node * 2, start, mid, left, right);
	int right_child = seg_sum(tree, node * 2 + 1, mid + 1, end, left, right);
	return left_child + right_child;
}

int main() {
	FASTIO;
	cin >> n >> s;
	int height = (int)ceil(log2(n));
	int tree_size = (1 << (height + 1));
	tree.resize(tree_size, 0);
	VINPUT(v, n);
	init(v, tree, 1, 0, n - 1);

	int start = 0, end = 0;
	int result = INF;
	while (start < n && end < n) {
		int tmp = seg_sum(tree, 1, 0, n - 1, start, end);
		// cout << start << " " << tmp << " " << end << endl;
		if (tmp < s) {
			end++;
		} else {
			result = min(result, end - start + 1);
			if (start == end) {
				end++;
			} else {
				start++;
			}
		}
	}
	if (result < INF) {
		cout << result;
	} else {
		cout << 0;
	}
}
