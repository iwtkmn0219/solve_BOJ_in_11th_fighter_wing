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

int tc;

int main() {
	FASTIO;
	cin >> tc;
	while (tc--) {
		int n, m, k; cin >> n >> m >> k;
		vvi board(n, vi(m, 0));
		vvi visit(n, vi(m, 0));
		while (k--) {
			int r, c; cin >> r >> c;
			board[r][c] = 1;
		}

		int d4[4][2] = dir4;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] && !visit[i][j]) {
					cnt++;
					// bfs
					queue<point> q;
					q.push({i, j});
					visit[i][j] = 1;
					while (!q.empty()) {
						point front = q.front();
						q.pop();
						for (int d = 0; d < 4; d++) {
							int nr = front.x + d4[d][0];
							int nc = front.y + d4[d][1];
							if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
								if (board[nr][nc] && !visit[nr][nc]) {
									q.push({nr, nc});
									visit[nr][nc] = 1;
								}
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
}
