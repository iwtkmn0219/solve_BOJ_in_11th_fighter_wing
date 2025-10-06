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

int n, m, d4[4][2] = dir4;
vector<string> board;
vvi visited;
queue<pi> q;

int bfs() {
	while (!q.empty()) {
		int cr = q.front().F;
		int cc = q.front().S;
		int stat = board[cr][cc];
		q.pop();
		for (auto d: d4) {
			int nr = cr + d[0];
			int nc = cc + d[1];
			if (board_condition(nr, nc, n, m)) {
				if (board[nr][nc] == '.' || board[nr][nc] == 'J') {
					if (stat == 'F') {
						board[nr][nc] = 'F';
						q.push({nr, nc});
					} else {
						if (!visited[nr][nc]) {
							visited[nr][nc] = visited[cr][cc] + 1;
							q.push({nr, nc});
						}
					}
				}
			} else {
				if (stat == 'J' || stat == '.') {
					return visited[cr][cc];
				}
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> n >> m;
	visited.resize(n, vi(m, 0));
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		board.PB(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'J') {
				visited[i][j] = 1;
				q.push({i, j});
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				visited[i][j] = 1;
				q.push({i, j});
			}
		}
	}
	int ans = bfs();
	if (ans == -1) {
		cout << "IMPOSSIBLE";
	} else {
		cout << ans;
	}
}
