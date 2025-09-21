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

int n, d4[4][2] = dir4;
vvi visited;
vector<string> board;

void bfs(int rr, int cc, int mode) {
	queue<pi> q;
	q.push({rr, cc});
	while (!q.empty()) {
		rr = q.front().F;
		cc = q.front().S;
		q.pop();
		for (auto d: d4) {
			int nr = rr + d[0];
			int nc = cc + d[1];
			if (board_condition(nr, nc, n, n) && !visited[nr][nc]) {
				if (mode == 1) {  // 색맹
					if (board[rr][cc] == 'R' || board[rr][cc] == 'G') {
						if (board[nr][nc] == 'R' || board[nr][nc] == 'G') {
							q.push({nr, nc});
							visited[nr][nc] = 1;
						}
					} else {
						if (board[nr][nc] == 'B') {
							q.push({nr, nc});
							visited[nr][nc] = 1;
						}
					}
				} else {  // 정상인
					if (board[rr][cc] == board[nr][nc]) {
						q.push({nr, nc});
						visited[nr][nc] = 1;
					}
				}
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> n;
	visited.resize(n, vi(n, 0));
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		board.PB(tmp);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j, 0);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j, 1);
				cnt++;
			}
		}
	}
	cout << cnt;
}
