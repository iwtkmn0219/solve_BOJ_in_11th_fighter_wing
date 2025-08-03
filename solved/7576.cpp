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
struct axis {
	int row, col;
};

int n, m;
int dir[4][2] = dir4;
vvi board, visited;
queue<axis> q;

int main() {
	FASTIO;
	cin >> n >> m;
	board.resize(m, vi(n, 0));
	visited.resize(m, vi(n, 0));
	bool all_red = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 0) {
				all_red = false;
			} else if (tmp == 1) {
				q.push({i, j});
				visited[i][j] = 1;
			}
		}
	}
	if (all_red) cout << 0;
	else {
		while (!q.empty()) {
			int r = q.front().row;
			int c = q.front().col;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dir[i][0];
				int nc = c + dir[i][1];
				if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
					if (!board[nr][nc] && !visited[nr][nc]) {
						q.push({nr, nc});
						visited[nr][nc] = visited[r][c] + 1;
					}
				}
			}
		}
		// V2DOUTPUT(visited);
		int maximum_time = 0;
		bool green_tomato = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] >= 0 && visited[i][j] == 0) {
					green_tomato = true;
				}
				maximum_time = max(maximum_time, visited[i][j]);
			}
		}
		if (green_tomato) cout << -1;
		else cout << maximum_time - 1;
	}
}
