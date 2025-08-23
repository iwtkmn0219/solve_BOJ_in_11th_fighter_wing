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
	int row, col, dust;
};

int n, m, t, d4[4][2] = dir4;
vvi board;

void spread() {
	queue<point> q;
	// 먼지가 있는 위치 큐에 넣기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] > 0) {
				q.push({i, j, board[i][j]});
			}
		}
	}
	// 큐에서 하나씩 빼서 확산시키기
	while (!q.empty()) {
		int rr = q.front().row;
		int cc = q.front().col;
		int dust = q.front().dust;
		q.pop();
		for (auto d: d4) {
			int nr = rr + d[0];
			int nc = cc + d[1];
			if (board_condition(nr, nc, n, m)) {
				if (board[nr][nc] != -1) {
					board[nr][nc] += dust / 5;
					board[rr][cc] -= dust / 5;
				}
			}
		}
	}
}

// 공기청정기
void air_circulator1(int row, int col) {
	int d_idx = 0;
	int rr = row, cc = col;
	while (true) {
		int nr = rr + d4[d_idx][0];
		int nc = cc + d4[d_idx][1];

		if (nr == row && nc == col) break;
		
		if (!board_condition(nr, nc, row + 1, m)) {
			d_idx++;
			nr = rr + d4[d_idx][0];
			nc = cc + d4[d_idx][1];
		}

		if (board[nr][nc] == -1) break;
		if (board[rr][cc] != -1) {
			board[rr][cc] = board[nr][nc];
		}
		board[nr][nc] = 0;

		rr = nr; cc = nc;
	}
}

void air_circulator2(int row, int col) {
	int d_idx = 2;
	int rr = row, cc = col;
	while (true) {
		int nr = rr + d4[d_idx][0];
		int nc = cc + d4[d_idx][1];

		if (nr == row && nc == col) break;

		if (!board_condition(nr - row, nc, n - row, m)) {
			d_idx--;
			if (d_idx < 0) d_idx += 4;
			nr = rr + d4[d_idx][0];
			nc = cc + d4[d_idx][1];
		}

		if (board[nr][nc] == -1) break;
		if (board[rr][cc] != -1) {
			board[rr][cc] = board[nr][nc];
		}
		board[nr][nc] = 0;

		rr = nr; cc = nc;
	}
}

int main() {
	// FASTIO;
	cin >> n >> m >> t;
	V2DINPUT(board, n, m);
	point p1 = {-1, -1}, p2 = {-1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == -1) {
				if (p1.row == -1) {
					p1.row = i;
					p1.col = j;
				} else {
					p2.row = i;
					p2.col = j;
				}
			}
		}
	}

	while (t--) {
		// 확산
		spread();
		NV2DOUTPUT(board);
		// 공기청정
		air_circulator1(p1.row, p1.col);
		air_circulator2(p2.row, p2.col);
		NV2DOUTPUT(board);
	}

	// 미세먼지 카운팅
	int total_dust = 0;
	for (auto row: board) {
		for (auto e: row) {
			if (e > 0) total_dust += e;
		}
	}
	cout << total_dust;
}
