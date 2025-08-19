#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
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

int n, e;
vvi graph;

int dijkstra(int start, int end) {
	if (start == end) return 0;
	vi dp(n + 1, INF);
	priority_queue<pi> pq;
	pq.push({0, start});
	dp[start] = 0;
	while (!pq.empty()) {
		int cn = pq.top().S;
		int dis = -pq.top().F;
		NWATCH(cn);
		pq.pop();

		if (dp[cn] < dis) continue;
		for (int nn = 1; nn <= n; nn++) {
			if (graph[cn][nn] != INF) {
				NWATCH(nn);
				int ndis = dis + graph[cn][nn];
				if (ndis < dp[nn]) {
					pq.push({-ndis, nn});
					dp[nn] = ndis;
				}
			}
		}
	}
	NVOUTPUT(dp);
	return dp[end];
}

int main() {
	FASTIO;
	cin >> n >> e;
	graph.resize(n + 1, vi(n + 1, INF));
	for (int i = 0; i < e; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u][v] = min(graph[u][v], w);
		graph[v][u] = min(graph[v][u], w);
	}
	int d1, d2; cin >> d1 >> d2;
	int tod1 = dijkstra(1, d1);
	int tod2 = dijkstra(1, d2);
	int d1d2 = dijkstra(d1, d2);
	int d1n = dijkstra(d1, n);
	int d2n = dijkstra(d2, n);

	int result1 = -1;
	if (d1d2 == INF) {
		cout << -1;
	} else {
		if (tod1 < INF && d2n < INF) {
			result1 = tod1 + d1d2 + d2n;
		}
		int result2 = -1;
		if (tod2 < INF && d1n < INF) {
			result2 = tod2 + d1d2 + d1n;
		}
		NWATCH(result1);
		NWATCH(result2);


		if (result1 == -1 && result2 == -1) {
			cout << -1;
		} else {
			if (result1 == -1) {
				cout << result2;
			} else if (result2 == -1) {
				cout << result1;
			} else {
				cout << min(result1, result2);
			}
		}
	}
}
