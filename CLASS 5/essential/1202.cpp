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
struct Jewel {
	int weight, value;
	bool operator<(const Jewel& j) {
		if (weight != j.weight) return weight < j.weight;
		return value < j.value;
	}
};

int n, k;
vi bag;
vector<Jewel> v;
vector<pi> tree;

pi init(int node, int v_start, int v_end) {
	if (v_start == v_end) return tree[node] = {v[v_start].value, v_start};
	int mid = (v_start + v_end) / 2;
	pi left_child = init(node * 2, v_start, mid);
	pi right_child = init(node * 2 + 1, mid + 1, v_end);

	return tree[node] = max(left_child, right_child);
}

pi find_max(int node, int t_start, int t_end, int v_start, int v_end) {
	if (t_start > v_end || t_end < v_start) return {0, 0};
	if (t_start >= v_start && t_end <= v_end) return tree[node];
	int mid = (t_start + t_end) / 2;
	pi left_child = find_max(node * 2, t_start, mid, v_start, v_end);
	pi right_child = find_max(node * 2 + 1, mid + 1, t_end, v_start, v_end);
	return max(left_child, right_child);
}

void update(int node, int t_start, int t_end, int idx) {
	if (t_start > idx || t_end < idx) return ;
	if (t_start == t_end) tree[node].F = 0;
	else {
		int mid = (t_start + t_end) / 2;
		update(node * 2, t_start, mid, idx);
		update(node * 2 + 1, mid + 1, t_end, idx);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

int main() {
	// FASTIO;
	cin >> n >> k;
	int tree_height = (int)ceil(log2(n + 2));
	int tree_size = (1 << (tree_height + 1));
	tree.resize(tree_size);
	v.PB({-1, -1});
	for (int i = 0; i < n; i++) {
		int weight, value; cin >> weight >> value;
		v.PB({weight, value});
	}
	v.PB({123456789, -1});
	for (int i = 0; i < k; i++) {
		int tmp; cin >> tmp;
		bag.PB(tmp);
	}
	SORT(v);
	SORT(bag);
	init(1, 0, v.size() - 1);  // 트리 생성
	ll result = 0;
	for (auto b: bag) {
		// 이분탐색으로 범위 정하기
		int start = 0, end = v.size() - 1;
		while (start + 1 < end) {
			int mid = (start + end) / 2;
			if (v[mid].weight <= b) start = mid;
			else end = mid;
		}
		
		if (v[start].value == -1) continue;
		pi max_p = find_max(1, 0, v.size() - 1, 0, start);
		result += (ll)max_p.F;
		update(1, 0, v.size() - 1, max_p.S);
	}
	cout << result;
}
