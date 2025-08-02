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
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << ; }
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << ; } cout << endl; }
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

map<ll, ll> dp;
int n;

ll recursion_dp(ll x) {
	if (x == 1) return 0;
	if (x == 2) return 1;
	// dp에 기록되어 있는 경우
	if (dp.find(x) != dp.end()) {
		return dp[x];
	}

	if (x % 2 == 0) {
		if (dp.find(x) == dp.end()) {
			dp[x] = (x / 2) * (x / 2) + 2 * recursion_dp(x / 2);
		}
		return dp[x];
	} else {
		if (dp.find(x) == dp.end()) {
			dp[x] = (x / 2) * (x / 2 + 1) + recursion_dp(x / 2) + recursion_dp(x / 2 + 1);
		}
		return dp[x];
	}
}

int main() {
	FASTIO;
	cin >> n;
	cout << recursion_dp(n);
}
