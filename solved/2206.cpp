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
	int row, col, crushed;
};

int direction[4][2] = dir4;
int n, m;
vector<string> board;

int bfs() {
	vector<vector<vector<int>>> visited(n, vvi(m, vi(2, 0)));
	queue<point> q;
	q.push({0, 0, 0});
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int rr = q.front().row;
		int cc = q.front().col;
		int crushed = q.front().crushed;
		q.pop();

		if (rr == n - 1 && cc == m - 1) break;
		for (auto d: direction) {
			int nr = rr + d[0];
			int nc = cc + d[1];
			
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				if (board[nr][nc] == '0' && !visited[nr][nc][crushed]) {
					visited[nr][nc][crushed] = visited[rr][cc][crushed] + 1;
					q.push({nr, nc, crushed});
				} else if (board[nr][nc] == '1' && crushed == 0) {
					visited[nr][nc][1] = visited[rr][cc][0] + 1;
					q.push({nr, nc, 1});
				}
			}
		}
	}
	if (visited[n - 1][m - 1][0] == 0) visited[n - 1][m - 1][0] = INF;
	if (visited[n - 1][m - 1][1] == 0) visited[n - 1][m - 1][1] = INF;
	
	return min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
}

int main() {
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmps; cin >> tmps;
		board.PB(tmps);
	}

	int result = bfs();
	if (result == INF) cout << -1;
	else cout << result;
}
