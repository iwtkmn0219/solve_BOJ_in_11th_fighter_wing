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
struct Point {
	int z, r, c;
};

int n, m, h, d6[6][3] = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
vector<vector<vector<int>>> board, visited;
queue<Point> q;

int bfs() {
	while (!q.empty()) {
		int ch = q.front().z, cr = q.front().r, cc = q.front().c; q.pop();
		for (auto d: d6) {
			int nh = ch + d[0], nr = cr + d[1], nc = cc + d[2];
			if (nh >= 0 && nr >= 0 && nc >= 0 && nh < h && nr < n && nc < m) {
				if (board[nh][nr][nc] == 0 && !visited[nh][nr][nc]) {
					q.push({nh, nr, nc});
					visited[nh][nr][nc] = visited[ch][cr][cc] + 1;
				}
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (visited[i][j][k] == 0 && board[i][j][k] == 0) {
					return -1;
				}
				maxi = max(maxi, visited[i][j][k]);
			}
		}
	}
	return maxi - 1;
}

int main() {
	FASTIO;
	cin >> m >> n >> h;
	board.resize(h, vvi(n, vi(m, 0)));
	visited.resize(h, vvi(n, vi(m, 0)));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tmp; cin >> tmp;
				board[i][j][k] = tmp;
				if (tmp == 1) {
					q.push({i, j, k});
					visited[i][j][k] = 1;
				}
			}
		}
	}
	
	cout << bfs() << endl;
	// for (int i = 0; i < h; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		for (int k = 0; k < m; k++) {
	// 			cout << visited[i][j][k] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << "---------" << endl;
	// }
}
