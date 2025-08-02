#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; }
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; }
#define WATCH(x) cout << #x << " : " << x << endl
#define DEBUG(x) cout << "DB - " << x << endl
#define PRINT(x) cout <<  x << endl
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
vi v, segment_tree;

/*
	start, end: 변환하고자 하는 배열의 인덱스
*/
int init_segment_tree(int node, int start, int end) {
	// base case
	if (start == end) return segment_tree[node] = v[start];

	int mid = (start + end) / 2;
	int left_child = init_segment_tree(node * 2, start, mid);
	int right_child = init_segment_tree(node * 2 + 1, mid + 1, end);
	segment_tree[node] = left_child + right_child;
	return segment_tree[node];
}

/*
	start, end: 노드 범위
	left, right: 찾고자 하는 범위
*/
int seg_sum(int node, int start, int end, int left, int right) {
	// base case
	if (start >= left && end <= right) return segment_tree[node];
	if (start > right || end < left) return 0;
	int left_sum = seg_sum(node * 2, start, (start + end) / 2, left, right);
	int right_sum = seg_sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return left_sum + right_sum;
}

int main() {
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.PB(tmp);
	}
	// setting segment tree
	segment_tree.resize(1 << ((int)ceil(log2(n)) + 1));
	init_segment_tree(1, 0, n - 1);
	while (m--) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		cout << seg_sum(1, 1, n, tmp1, tmp2) << endl;
	}
}
