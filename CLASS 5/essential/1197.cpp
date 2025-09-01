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
struct Edge {
	int cost, u, v;
	bool operator<(const Edge &edge) {
		if (cost != edge.cost) return cost < edge.cost;
		else if (u != edge.u) return u < edge.u;
		else return v < edge.v;
	}
};

int v, e;
vi parrent;
vector<Edge> ve;

int find(int x) {
	if (parrent[x] == x) return x;
	else return parrent[x] = find(parrent[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parrent[y] = x;
}

bool same_root(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}

int main() {
	FASTIO;
	int result = 0;
	cin >> v >> e;
	parrent.resize(v + 1, 0);
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		ve.PB({c, a, b});
	}
	SORT(ve);
	for (int i = 1; i <= v; i++) parrent[i] = i;
	for (auto elem: ve) {
		if (!same_root(elem.u, elem.v)) {
			uni(elem.u, elem.v);
			result += elem.cost;
		}
	}
	cout << result;
}
