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

int n;
vvi main_board;

void left(vvi& board) {
	for (int row = 0; row < n; row++) {
		int s = 0, e = 1;
		while (true) {
			if (e >= n) break;

			if (board[row][e] > 0) {
				if (board[row][s] == board[row][e]) {
					board[row][s++] += board[row][e];
					board[row][e] = 0;
				} else if (board[row][s] == 0) {
					board[row][s] += board[row][e];
					board[row][e] = 0;
				} else {
					s++;
					board[row][s] = board[row][e];
					if (s != e)
						board[row][e] = 0;
				}
			}
			e++;
		}
	}
}

void right(vvi& board) {
	for (int row = 0; row < n; row++) {
		int s = n - 1, e = n - 2;
		while (true) {
			if (e < 0) break;

			if (board[row][e] > 0) {
				if (board[row][s] == board[row][e]) {
					board[row][s--] += board[row][e];
					board[row][e] = 0;
				} else if (board[row][s] == 0) {
					board[row][s] += board[row][e];
					board[row][e] = 0;
				} else {
					s--;
					board[row][s] = board[row][e];
					if (s != e)
						board[row][e] = 0;
				}
			}
			e--;
		}
	}
}

void up(vvi& board) {
	for (int col = 0; col < n; col++) {
		int s = 0, e = 1;
		while (true) {
			if (e >= n) break;
			if (board[e][col] > 0) {
				if (board[s][col] == board[e][col]) {
					board[s++][col] += board[e][col];
					board[e][col] = 0;
				} else if (board[s][col] == 0) {
					board[s][col] += board[e][col];
					board[e][col] = 0;
				} else {
					s++;
					board[s][col] = board[e][col];
					if (s != e)
						board[e][col] = 0;
				}
			}
			e++;
		}
	}
}

void down(vvi& board) {
	for (int col = 0; col < n; col++) {
		int s = n - 1, e = n - 2;
		while (true) {
			if (e < 0) break;
			if (board[e][col] > 0) {
				if (board[s][col] == board[e][col]) {
					board[s--][col] += board[e][col];
					board[e][col] = 0;
				} else if (board[s][col] == 0) {
					board[s][col] += board[e][col];
					board[e][col] = 0;
				} else {
					s--;
					board[s][col] = board[e][col];
					if (s != e)
						board[e][col] = 0;
				}
			}
			e--;
		}
	}
}

void copy(vvi& from, vvi& to) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			to[i][j] = from[i][j];
		}
	}
}

int recursion(int depth, vvi board) {
	int result = 0;
	NWATCH(depth);
	NV2DOUTPUT(board);
	if (depth == 5) {
		for (auto row: board) {
			for (auto e: row) {
				result = max(result, e);
			}
		}
		NWATCH(result);
		return result;
	}
	vvi tmp_board(n, vi(n, 0));
	copy(board, tmp_board);
	left(tmp_board);
	result = max(result, recursion(depth + 1, tmp_board));

	copy(board, tmp_board);
	right(tmp_board);
	result = max(result, recursion(depth + 1, tmp_board));

	copy(board, tmp_board);
	up(tmp_board);
	result = max(result, recursion(depth + 1, tmp_board));

	copy(board, tmp_board);
	down(tmp_board);
	result = max(result, recursion(depth + 1, tmp_board));
	return result;
}

int main() {
	FASTIO;
	cin >> n;
	V2DINPUT(main_board, n, n);
	cout << recursion(0, main_board);
}
