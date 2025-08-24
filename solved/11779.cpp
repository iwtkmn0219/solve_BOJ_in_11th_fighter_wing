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

int n, m;
vector<vector<pi>> graph;

void dijkstra(int start, int end) {
	priority_queue<pi> pq;
	vector<pair<int, vi>> dp(n + 1);
	for (int i = 1; i < n + 1; i++) {
		dp[i].F = INF;
	}
	pq.push({0, start});
	dp[start].F = 0;
	dp[start].S.PB(start);
	while (!pq.empty()) {
		int cn = pq.top().S;
		int dis = -pq.top().F;
		pq.pop();
		if (dis > dp[cn].F) continue;
		for (auto next: graph[cn]) {
			int nn = next.F;
			int ndis = dis + next.S;
			if (ndis < dp[nn].F) {
				// pq push
				pq.push({-ndis, nn});
				dp[nn].F = ndis;
				// vector update
				dp[nn].S.clear();
				for (auto e: dp[cn].S) {
					dp[nn].S.PB(e);
				}
				dp[nn].S.PB(nn);
			}
		}
	}
	cout << dp[end].F << endl;
	cout << dp[end].S.size() << endl;
	VOUTPUT(dp[end].S);
}

int main() {
	FASTIO;
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].PB({v, w});
	}
	int start, end; cin >> start >> end;
	dijkstra(start, end);
}
