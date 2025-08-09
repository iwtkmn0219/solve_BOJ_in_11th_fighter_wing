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

int v, e, k;
vector<vector<pi>> graph;
vi dp;
priority_queue<pi> q;

int main() {
	FASTIO;
	cin >> v >> e >> k;
	graph.resize(v + 1);
	dp.resize(v + 1, INF);
	REP(i, 0, e) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].PB({v, w});
	}
	
	q.push({0, k});
	dp[k] = 0;
	while (!q.empty()) {
		int cn = q.top().S;
		int distance = -q.top().F;
		q.pop();
		if (dp[cn] < distance) continue;
		for (int i = 0; i < graph[cn].size(); i++) {
			int nn = graph[cn][i].F;
			int next_distance = graph[cn][i].S + distance;
			if (next_distance < dp[nn]) {
				dp[nn] = next_distance;
				q.push({-next_distance, nn});
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dp[i] >= INF) {
			cout << "INF" << endl;
		} else {
			cout << dp[i] << endl;
		}
	}
}
