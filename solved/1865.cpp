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
struct edge {
	int start, end, weight;
};

int tc;

int main() {
	FASTIO;
	cin >> tc;
	while (tc--) {
		int n, m, whall; cin >> n >> m >> whall;
		vvi graph(n + 1, vi(n + 1, INF));
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			graph[u][v] = min(graph[u][v], w);
			graph[v][u] = min(graph[v][u], w);
		}
		for (int i = 0; i < whall; i++) {
			int u, v, w; cin >> u >> v >> w;
			graph[u][v] = min(graph[u][v], -w);
		}
		
		vector<edge> edges;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][j] == INF) continue;
				edges.PB({i, j, graph[i][j]});
			}
		}

		bool ncycle_flag = false;
		// bellman ford
		vi visited(n + 1, INF);
		visited[1] = 0;
		// bellman ford ch 1
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < edges.size(); j++) {
				int start = edges[j].start;
				int end = edges[j].end;
				int next_distance = visited[start] + edges[j].weight;
				if (visited[end] > next_distance) {
					visited[end] = next_distance;
				}
			}
		}
		// bellman ford ch 2 (check cycle)
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < edges.size(); j++) {
				int start = edges[j].start;
				int end = edges[j].end;
				int next_distance = visited[start] + edges[j].weight;
				if (visited[end] > next_distance) {
					visited[end] = next_distance;
					ncycle_flag = true;
				}
			}
		}
		if (ncycle_flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
