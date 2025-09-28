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

int n, l, d4[4][2] = dir4;
vvi board;

bool check_flat(int row, int col, int d) {
	if (row + d4[d][0] * l < 0 || row + d4[d][0] * l >= n) return false;
	if (col + d4[d][1] * l < 0 || col + d4[d][1] * l >= n) return false;
	int standard = board[row][col] - 1;
	for (int i = 0; i < l; i++) {
		row += d4[d][0];
		col += d4[d][1];
		if (board[row][col] != standard) return false;
	}
	return true;
}

bool check_runway(vi& v, int idx, int d) {
	for (int i = 0; i < l; i++) {
		idx += d;
		if (v[idx] == 1) return false;
	}
	return true;
}

bool check_row(int row) {
	vi runway(n, 0);
	for (int col = 1; col < n; col++) {
		if (board[row][col] > board[row][col - 1]) {
			// 높아지는 경우
			if (check_flat(row, col, 3)) {
				if (check_runway(runway, col, -1)) {
					int tmp = col;
					for (int i = 0; i < l; i++) {
						tmp -= 1;
						runway[tmp] = 1;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else if (board[row][col] < board[row][col - 1]) {
			// 낮아지는 경우
			if (check_flat(row, col - 1, 1)) {
				if (check_runway(runway, col - 1, 1)) {
					int tmp = col - 1;
					for (int i = 0; i < l; i++) {
						tmp += 1;
						runway[tmp] = 1;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
			col += l - 1;
		}
	}
	return true;
}

bool check_col(int col) {
	vi runway(n, 0);
	for (int row = 1; row < n; row++) {
		if (board[row][col] > board[row - 1][col]) {
			// 높아지는 경우
			if (check_flat(row, col, 0)) {
				if (check_runway(runway, row, -1)) {
					int tmp = row;
					for (int i = 0; i < l; i++) {
						tmp -= 1;
						runway[tmp] = 1;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else if (board[row][col] < board[row - 1][col]) {
			// 낮아지는 경우
			if (check_flat(row - 1, col, 2)) {
				if (check_runway(runway, row - 1, 1)) {
					int tmp = row - 1;
					for (int i = 0; i < l; i++) {
						tmp += 1;
						runway[tmp] = 1;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
			row += l - 1;
		}
	}
	return true;
}

int main() {
	FASTIO;
	cin >> n >> l;
	V2DINPUT(board, n, n);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		NWATCH(i);
		NWATCH(check_row(i));
		if (check_row(i)) cnt++;
	}

	for (int i = 0; i < n; i++) {
		NWATCH(i);
		NWATCH(check_col(i));
		if (check_col(i)) cnt++;
	}

	cout << cnt;
	
}
