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
#define VOUTPUT(v) REP(i, 0, 20) { cout << v[i] << " "; } cout << endl
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, 20) { cout << v[i][j] << " "; } cout << endl; } cout << endl
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

int c, n;
vector<pi> vp;
vvi dp_table;

int main() {
	FASTIO;
	cin >> c >> n;
	dp_table.resize(n + 1, vi(2000, INF));
	for (int i = 0; i < n; i++) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		vp.PB({tmp2, tmp1});
	}
	SORT(vp);
	for (int row = 1; row <= n; row++) {
		int cost = vp[row - 1].S;
		int people = vp[row - 1].F;
		dp_table[row][people] = cost;
		dp_table[row][0] = 0;
		for (int col = 1; col < 2000; col++) {
			if (col >= people) {
				dp_table[row][col] = min(dp_table[row - 1][col], dp_table[row][col - people] + cost);
			} else {
				dp_table[row][col] = dp_table[row - 1][col];
			}
		}
		NV2DOUTPUT(dp_table);
	}

	int result = INF;
	for (int i = c; i < 2000; i++) {
		result = min(result, dp_table[n][i]);
	}
	cout << result;
}
