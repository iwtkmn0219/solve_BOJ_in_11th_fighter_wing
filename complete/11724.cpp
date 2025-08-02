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
vi visited;
vvi graph;

int main() {
	FASTIO;
	cin >> n >> m;
	graph.resize(n + 1, vi(n + 1, 0));
	visited.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int node1, node2; cin >> node1 >> node2;
		graph[node1][node2] = 1;
		graph[node2][node1] = 1;
	}

	queue<int> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			q.push(i);
			visited[i] = 1;
			while (!q.empty()) {
				int front = q.front();
				q.pop();
				for (int nn = 1; nn <= n; nn++) {
					if (!visited[nn] && graph[front][nn]) {
						q.push(nn);
						visited[nn] = 1;
					}
				}
			}
		}
	}
	cout << cnt;
}
