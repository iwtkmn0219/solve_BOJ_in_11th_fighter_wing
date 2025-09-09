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

string s1, s2;
vvi backtrack;
vvi dp;

string print_lcs() {
	string result = "";
	int row = dp.size() - 1, col = dp[0].size() - 1;
	while (row > 0 && col > 0) {
		if (backtrack[row][col] == 2) {
			col--;
		} else if (backtrack[row][col] == 1) {
			result += s1[col - 1];
			row--; col--;
		} else {
			row--;
		}
	}
	REV(result);
	return result;
}

int main() {
	// FASTIO;
	cin >> s1 >> s2;
	backtrack.resize(s2.size() + 1, vi(s1.size() + 1, 0));
	dp.resize(s2.size() + 1, vi(s1.size() + 1, 0));
	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s2[i - 1] == s1[j - 1]) {
				if (dp[i - 1][j - 1] + 1 > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					backtrack[i][j] = 1;
				} else {
					dp[i][j] = dp[i][j - 1];
					backtrack[i][j] = 2;
				}
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (dp[i - 1][j] < dp[i][j - 1]) {
					backtrack[i][j] = 2;
				} else {
					backtrack[i][j] = 0;
				}
			}
		}
	}
	cout << dp[s2.size()][s1.size()] << endl;
	cout << print_lcs();
}
