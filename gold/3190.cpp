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

int n, k, l, d4[4][2] = dir4;
queue<pair<int, char>> turn_time;
queue<pi> tail;
vvi board;

int main() {
	FASTIO;
	cin >> n >> k;
	board.resize(n, vi(n, 0));
	for (int i = 0; i < k; i++) {
		int r, c; cin >> r >> c;
		board[r - 1][c - 1] = 5;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t;
		char dir;
		cin >> t >> dir;
		turn_time.push({t, dir});
	}
	int time = 0, cr = 0, cc = 0, d = 1;
	board[0][0] = 1;
	tail.push({0, 0});
	while (true) {
		time++;
		int nr = cr + d4[d][0];
		int nc = cc + d4[d][1];
		if (!board_condition(nr, nc, n, n)) break;
		if (board[nr][nc] == 1) break;
		if (board[nr][nc] != 5) {
			int trow = tail.front().F;
			int tcol = tail.front().S;
			tail.pop();
			board[trow][tcol] = 0;
		}
		board[nr][nc] = 1;
		tail.push({nr, nc});
		cr = nr;
		cc = nc;
		if (turn_time.front().F == time) {
			if (turn_time.front().S == 'L') {
				d = (d + 3) % 4;
			} else {
				d = (d + 1) % 4;
			}
			turn_time.pop();
		}
	}
	cout << time;
}
