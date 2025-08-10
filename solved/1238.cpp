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

int n, m, x;
vector<vector<pi>> graph;

// m + nlogn < 10 ^ 5
int dijkstra(int start, int end) {
	vi visited(n + 1, INF);
	priority_queue<pi> pq;
	pq.push({0, start});
	visited[start] = 0;
	while (!pq.empty()) {
		int cn = pq.top().S;
		int distance = -pq.top().F;
		pq.pop();
		if (visited[cn] < distance) continue;
		for (int i = 0; i < graph[cn].size(); i++) {
			int nn = graph[cn][i].F;
			int n_distance = graph[cn][i].S + distance;
			if (n_distance < visited[nn]) {
				visited[nn] = n_distance;
				pq.push({-n_distance, nn});
			}
		}
	}
	return visited[end];
}

int main() {
	FASTIO;
	// input
	cin >> n >> m >> x;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].PB({v, w});
	}
	int maximum = 0;
	// dijkstra each node
	for (int i = 1; i <= n; i++) {
		// dijkstra 
		if (i == x) continue;
		int total_distance = dijkstra(i, x) + dijkstra(x, i);
		maximum = max(maximum, total_distance);
	}
	cout << maximum;
}
