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
	int x, y;
};

int n, m, d4[4][2] = dir4;
vector<pi> cctv_position;
vvi board;

void cctv134(vvi& v, int row, int col, int direction, int cctv_mode) {
	if (cctv_mode > 2) cctv_mode--;
	for (int i = 0; i < cctv_mode; i++) {
		int rr = row, cc = col;
		while (true) {
			rr += d4[(direction + i) % 4][0];
			cc += d4[(direction + i) % 4][1];
			if (!board_condition(rr, cc, n, m)) break ;
			if (board[rr][cc] == 6) break;
			if (board[rr][cc] > 0) continue;
			v[rr][cc] = 7;
		}
	}
}

void cctv2(vvi& v, int row, int col, int direction) {
	for (int i = 0; i < 3; i += 2) {
		int rr = row, cc = col;
		while (true) {
			rr += d4[(direction + i) % 4][0];
			cc += d4[(direction + i) % 4][1];
			if (!board_condition(rr, cc, n, m)) break ;
			if (board[rr][cc] == 6) break;
			if (board[rr][cc] > 0) continue;
			v[rr][cc] = 7;
		}
	}
}

void cctv5(vvi& v, int row, int col) {
	for (int i = 0; i < 4; i++) {
		int rr = row, cc = col;
		while (true) {
			rr += d4[i][0];
			cc += d4[i][1];
			if (!board_condition(rr, cc, n, m)) break ;
			if (board[rr][cc] == 6) break;
			if (board[rr][cc] > 0) continue;
			v[rr][cc] = 7;
		}
	}
}

void copy_board(vvi& reference, vvi & destination) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			destination[i][j] = reference[i][j];
}

int count_black_area(vvi& v) {
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (v[i][j] == 0) cnt++;
	return cnt;
}

int recursion(vvi v, int idx) {
	NWATCH(idx);
	if (idx >= cctv_position.size()) {
		NV2DOUTPUT(v);
		return count_black_area(v);
	}
	int row = cctv_position[idx].F, col = cctv_position[idx].S;
	int mode = board[row][col];
	vvi tmp(n, vi(m, 0));

	int mini = INF;
	if (mode == 2) {
		copy_board(v, tmp);
		cctv2(tmp, row, col, 0);
		mini = min(mini, recursion(tmp, idx + 1));
		copy_board(v, tmp);
		cctv2(tmp, row, col, 1);
		mini = min(mini, recursion(tmp, idx + 1));
	} else if(mode == 5) {
		copy_board(v, tmp);
		cctv5(tmp, row, col);
		mini = recursion(tmp, idx + 1);
	} else {
		for (int i = 0; i < 4; i++) {
			copy_board(v, tmp);
			cctv134(tmp, row, col, i, mode);
			mini = min(mini, recursion(tmp, idx + 1));
		}
	}
	return mini;
}

int main() {
	FASTIO;
	cin >> n >> m;
	V2DINPUT(board, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] > 0 && board[i][j] < 6) {
				cctv_position.PB({i, j});
			}
		}
	}
	// WATCH(cctv_position.size());
	// WATCH(recursion(board, 0));
	cout << recursion(board, 0);
}
