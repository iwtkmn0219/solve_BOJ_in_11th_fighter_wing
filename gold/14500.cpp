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

int n, m;
vvi board;

int t1() {
	int maxi = 0;
	int piece[2][4][2] = {
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}}
	};
	for (int i = 0; i < 2; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				int tmp = 0;
				for (auto p: piece[i]) {
					int nr = r + p[0];
					int nc = c + p[1];
					if (board_condition(nr, nc, n, m)) {
						tmp += board[nr][nc];
					} else {
						tmp -= 10000;
						break;
					}
				}
				maxi = max(maxi, tmp);
			}
		}
	}
	return maxi;
}

int t2() {
	int maxi = 0;
	int piece[1][4][2] = {
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}}
	};
	for (int i = 0; i < 1; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				int tmp = 0;
				for (auto p: piece[i]) {
					int nr = r + p[0];
					int nc = c + p[1];
					if (board_condition(nr, nc, n, m)) {
						tmp += board[nr][nc];
					} else {
						tmp -= 10000;
						break;
					}
				}
				maxi = max(maxi, tmp);
			}
		}
	}
	return maxi;
}

int t3() {
	int maxi = 0;
	int piece[8][4][2] = {
		// 기본
		{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {0, 2}},
		{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
		{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
		// 대칭
		{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
		{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
		{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 2}}
	};
	for (int i = 0; i < 8; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				int tmp = 0;
				for (auto p: piece[i]) {
					int nr = r + p[0];
					int nc = c + p[1];
					if (board_condition(nr, nc, n, m)) {
						tmp += board[nr][nc];
					} else {
						tmp -= 10000;
						break;
					}
				}
				maxi = max(maxi, tmp);
			}
		}
	}
	return maxi;
}

int t4() {
	int maxi = 0;
	int piece[4][4][2] = {
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
		// 대칭
		{{0, 0}, {0, 1}, {1, 0}, {-1, 1}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}}
	};
	for (int i = 0; i < 4; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				int tmp = 0;
				for (auto p: piece[i]) {
					int nr = r + p[0];
					int nc = c + p[1];
					if (board_condition(nr, nc, n, m)) {
						tmp += board[nr][nc];
					} else {
						tmp -= 10000;
						break;
					}
				}
				maxi = max(maxi, tmp);
			}
		}
	}
	return maxi;
}

int t5() {
	int maxi = 0;
	int piece[4][4][2] = {
		{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
		{{0, 0}, {0, 1}, {-1, 1}, {1, 1}},
		{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
		{{0, 0}, {1, 0}, {2, 0}, {1, 1}}
	};
	for (int i = 0; i < 4; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				int tmp = 0;
				for (auto p: piece[i]) {
					int nr = r + p[0];
					int nc = c + p[1];
					if (board_condition(nr, nc, n, m)) {
						tmp += board[nr][nc];
					} else {
						tmp -= 10000;
						break;
					}
				}
				maxi = max(maxi, tmp);
			}
		}
	}
	return maxi;
}

int main() {
	FASTIO;
	cin >> n >> m;
	V2DINPUT(board, n, m);
	int result = max(t1(), max(t2(), max(t3(), max(t4(), t5()))));
	cout << result;
}
