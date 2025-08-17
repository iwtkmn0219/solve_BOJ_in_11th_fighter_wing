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
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; } cout << endl
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

int n, m, start_point, end_point;
priority_queue<pi> pq;
vector<vector<pi>> graph;
vi dp;

int main() {
	FASTIO;
	cin >> n >> m;
	graph.resize(n + 1);
	dp.resize(n + 1, INF);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].PB({v, w});
	}
	cin >> start_point >> end_point;

	pq.push({0, start_point});
	dp[start_point] = 0;
	while (!pq.empty()) {
		int cn = pq.top().S;
		int dis = -pq.top().F;
		pq.pop();

		if (dis > dp[cn]) continue;
		for (auto next_point: graph[cn]) {
			int nn = next_point.F;
			int ndis = dis + next_point.S;
			if (ndis < dp[nn]) {
				dp[nn] = ndis;
				pq.push({-ndis, nn});
			}
		}
	}
	VOUTPUT(dp);
	cout << dp[end_point];
}
