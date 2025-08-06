#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; }
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; }
#define WATCH(x) cout << #x << " : " << x << endl
#define DEBUG(x) cout << "DB - " << x << endl
#define PRINT(x) cout <<  x << endl
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

int tc;
int n;

int main() {
	FASTIO;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vvi board(2, vi(n, 0)), dp(2, vi(n, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				int tmp; cin >> tmp;
				board[i][j] = tmp;
			}
		}
		dp[0][0] = board[0][0];
		dp[1][0] = board[1][0];
		int maximum = max(dp[0][0], dp[1][0]);
		for (int i = 1; i < n; i++) {
			if (i == 1) {
				dp[0][1] = board[0][1] + dp[1][0];
				dp[1][1] = board[1][1] + dp[0][0];
			} else {
				int tmp_max = max(dp[0][i - 2], dp[1][i - 2]);
				dp[0][i] = board[0][i] + max(dp[1][i - 1], tmp_max);
				dp[1][i] = board[1][i] + max(dp[0][i - 1], tmp_max);
			}
			maximum = max(maximum, max(dp[0][i], dp[1][i]));
		}
		cout << maximum << endl;
	}
}
