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

int n;
vector<vector<pi>> graph;

pi bfs(int start) {
	int maxi = 0, maxn = 0;
	vi visited(n + 1, 0);
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int cn = q.front();
		q.pop();
		for (int i = 0; i < graph[cn].size(); i++) {
			int nn = graph[cn][i].F;
			int ndis = graph[cn][i].S;
			if (!visited[nn]) {
				visited[nn] = visited[cn] + ndis;
				q.push(nn);
				if (visited[nn] > maxn) {
					maxi = nn;
					maxn = visited[nn];
				}
			}
		}
	}
	return {maxi, maxn - 1};
}

int main() {
	FASTIO;
	cin >> n;
	graph.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int pn; cin >> pn;
		int tmp;
		while (true) {
			cin >> tmp;
			if (tmp == -1) {
				break;
			} else {
				int w; cin >> w;
				graph[pn].PB({tmp, w});
			}
		}
	}
	pi tmp = bfs(1);
	// cout << tmp.F << " " << tmp.S;
	pi tmp2 = bfs(tmp.F);
	cout << tmp2.S;
}
