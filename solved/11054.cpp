#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; } cout << endl
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; }
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
vi v;
vvi dp;

int main() {
	FASTIO;
	cin >> n;
	v.PB(0);
	VINPUT(v, n);
	v.PB(0);
	if (n <= 2) {
		cout << n;
	} else {
		dp.resize(2, vi(n + 2, 0));
		// 오른쪽으로 증가
		for (int i = 1; i <= n; i++) {
			int maxn = 0;
			for (int j = 0; j < i; j++) {
				if (v[j] < v[i]) {
					maxn = max(maxn, dp[0][j]);
				}
			}
			dp[0][i] = maxn + 1;
		}
		// 왼쪽으로 증가
		for (int i = n; i >= 1; i--) {
			int maxn = 0;
			for (int j = n + 1; j > i; j--) {
				if (v[j] < v[i]) {
					maxn = max(maxn, dp[1][j]);
				}
			}
			dp[1][i] = maxn + 1;
		}
		NV2DOUTPUT(dp);

		int result = 0;
		for (int i = 1; i < n + 1; i++) {
			result = max(result, dp[0][i] + dp[1][i] - 1);
		}
		cout << result;
	}
}
