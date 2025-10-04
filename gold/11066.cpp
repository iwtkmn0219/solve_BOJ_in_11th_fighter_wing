#include <bits/stdc++.h>
#define endl "\n"
#define INF 2e9
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

int tc;

int main() {
	FASTIO;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vi v, psum;
		vvi dp;
		v.PB(0);
		psum.PB(0);
		for (int i = 1; i <= n; i++) {
			int tmp; cin >> tmp;
			v.PB(tmp);
			psum.PB(psum[psum.size() - 1] + tmp);
		}
		dp.resize(n + 1, vi(n + 1, INF));
		for (int d = 0; d < n; d++) {
			for (int i = 1; i <= n - d; i++) {
				if (d == 0) {
					dp[i][i] = 0;
					continue;
				}
				for (int k = i; k < i + d; k++) {
					dp[i][i + d] = min(dp[i][i + d], dp[i][k] + dp[k + 1][i + d] + (psum[k] - psum[i - 1]) + (psum[i + d] - psum[k]));
				}
				NV2DOUTPUT(dp);
			}
		}
		cout << dp[1][n] << endl;
	}
}
