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

int n, k;
vvi dp(250000, vi(2, 0));

int main() {
	FASTIO;
	cin >> n >> k;
	if (n == k) {
		cout << 0 << endl << 1;
		return 0;
	}
	queue<int> q;
	q.push(n);
	dp[n][0] = 1;
	dp[n][1] = 1;
	int result = 0;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		if (curr - 1 >= 0) {
			if (!dp[curr - 1][0]) {
				dp[curr - 1][0] = dp[curr][0] + 1;
				dp[curr - 1][1] += dp[curr][1];
				q.push(curr - 1);
			} else if (dp[curr - 1][0] == dp[curr][0] + 1) {
				dp[curr - 1][1] += dp[curr][1];
			}
		}
		if (curr + 1 < 250000) {
			if (!dp[curr + 1][0]) {
				dp[curr + 1][0] = dp[curr][0] + 1;
				dp[curr + 1][1] += dp[curr][1];
				q.push(curr + 1);
			} else if (dp[curr + 1][0] == dp[curr][0] + 1) {
				dp[curr + 1][1] += dp[curr][1];
			}
		}
		if (curr > 0 && curr * 2 < 250000) {
			if (!dp[curr * 2][0]) {
				dp[curr * 2][0] = dp[curr][0] + 1;
				dp[curr * 2][1] += dp[curr][1];
				q.push(curr * 2);
			} else if (dp[curr * 2][0] == dp[curr][0] + 1) {
				dp[curr * 2][1] += dp[curr][1];
			}
		}
	}
	cout << dp[k][0] - 1 << endl;
	cout << dp[k][1];
}
