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

int n, m, d4[4][2] = dir4, finish_value, cnt = 0;
vvi board;
vector<vector<ll>> dp;

int dfs(int rr, int cc) {
	cnt++;
	if (rr == n - 1 && cc == m - 1) {
		return 1;
	}
	int curr_value = board[rr][cc];
	for (auto d: d4) {
		int nr = rr + d[0];
		int nc = cc + d[1];
		if (board_condition(nr, nc, n, m)) {
			// 다음 셀의 값은 지금 값보다 낮아야 함
			// 다음 셀의 값은 마지막 값보다는 크거나 마지막 셀이어야함
			if (board[nr][nc] < curr_value) {
				if (board[nr][nc] > finish_value || (nr == n - 1 && nc == m - 1)) {
					if (dp[nr][nc] > 0) {
						dp[rr][cc] += dp[nr][nc];
					} else if (dp[nr][nc] == 0) {
						int tmp = dfs(nr, nc);
						if (tmp > 0)
							dp[rr][cc] += tmp;
					}
				}
			}
		}
	}
	if (dp[rr][cc] == 0) {
		dp[rr][cc] = -1;
	}
	NV2DOUTPUT(dp);
	return dp[rr][cc];
}

int main() {
	FASTIO;
	cin >> n >> m;
	dp.resize(n, vector<ll>(m, 0));
	V2DINPUT(board, n, m);
	finish_value = board[n - 1][m - 1];
	dfs(0, 0);
	NV2DOUTPUT(dp);
	NWATCH(cnt);
	if (dp[0][0] == -1) {
		cout << 0;
	} else {
		cout << dp[0][0];	
	}
}
