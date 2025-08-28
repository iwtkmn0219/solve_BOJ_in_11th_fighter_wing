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

int n, m ,r;
vi item_list(1, 0);
vector<vector<pi>> graph;

int dijkstra(int start) {
	priority_queue<pi> pq;
	vi dp(n + 1, INF);
	pq.push({0, start});
	dp[start] = 0;
	while (!pq.empty()) {
		int curr = pq.top().S;
		int dis = -pq.top().F;
		pq.pop();
		if (dp[curr] < dis) continue;
		for (auto next: graph[curr]) {
			int nn = next.F;
			int ndis = next.S + dis;
			if (ndis < dp[nn]) {
				pq.push({-ndis, nn});
				dp[nn] = ndis;
			}
		}
	}
	NWATCH(start);
	NVOUTPUT(dp);
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] <= m) result += item_list[i];
	}
	NWATCH(result);
	return result;
}

int main() {
	FASTIO;
	cin >> n >> m >> r;
	graph.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		item_list.PB(tmp);
	}
	for (int i = 0; i < r; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].PB({v, w});
		graph[v].PB({u, w});
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		maxi = max(maxi, dijkstra(i));
	}
	cout << maxi;
}
