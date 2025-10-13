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

int n, m, d4[4][2] = dir4, rr, cc, d, ans = 0;
vvi board;

bool is_finish() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool can_clean(int row, int col) {
	for (auto d: d4) {
		int nr = row + d[0];
		int nc = col + d[1];
		if (board_condition(nr, nc, n, m)) {
			if (board[nr][nc] == 0) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	cin >> n >> m >> rr >> cc >> d;
	V2DINPUT(board, n, m);
	while (is_finish()) {
		if (board[rr][cc] == 0) {
			board[rr][cc] = 2;
			ans++;
		}
		if (can_clean(rr, cc)) {
			d = (d + 3) % 4;
			int nr = rr + d4[d][0];
			int nc = cc + d4[d][1];
			if (board_condition(nr, nc, n, m) && board[nr][nc] == 0) {
				rr = nr;
				cc = nc;
			}
		} else {
			int nr = rr + d4[(d + 2) % 4][0];
			int nc = cc + d4[(d + 2) % 4][1];
			if (board_condition(nr, nc, n, m) && board[nr][nc] != 1) {
				rr = nr;
				cc = nc;
			} else {
				break;
			}
		}
	}
	cout << ans;
}
