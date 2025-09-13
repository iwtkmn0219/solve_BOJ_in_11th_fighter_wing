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
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j]; } cout << endl; }
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

vector<string> board;

void print_bit(int x) {
	for (int i = 9; i >= 1; i--) {
		if (x & (1 << i)) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << endl;
}

int emptyCell() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '0') {
				return i * 9 + j;
			}
		}
	}
	return -1;
}

int check_row(int row, int col) {
	int result = 0;
	for (int c = 0; c < 9; c++) {
		result |= (1 << (board[row][c] - '0'));
	}
	return result;
}

int check_col(int row, int col) {
	int result = 0;
	for (int r = 0; r < 9; r++) {
		result |= (1 << (board[r][col] - '0'));
	}
	return result;
}

int check_box(int row, int col) {
	int result = 0;
	row = (row / 3) * 3;
	col = (col / 3) * 3;
	for (int r = row; r < row + 3; r++) {
		for (int c = col; c < col + 3; c++) {
			result |= (1 << (board[r][c] - '0'));
		}
	}
	return result;
}

int recursion() {
	int ecell = emptyCell();
	if (ecell == -1) {
		V2DOUTPUT(board);
		return -1;
	}
	int erow = ecell / 9, ecol = ecell % 9;
	NV2DOUTPUT(board);
	// cout << "ECELL: " << erow << " " << ecol << endl;
	int possible = check_row(erow, ecol) | check_col(erow, ecol) | check_box(erow, ecol);
	// print_bit(possible);
	for (int i = 1; i <= 9; i++) {
		if (!(possible & (1 << i))) {
			board[erow][ecol] = i + '0';
			int result = recursion();
			if (result == -1) return -1;
			board[erow][ecol] = '0';
		}
	}
	return 1;
}

int main() {
	FASTIO;
	for (int i = 0; i < 9; i++) {
		string tmp; cin >> tmp;
		board.PB(tmp);
	}
	// print_bit(check_col(0, 1));
	recursion();
	// V2DOUTPUT(board);
}
