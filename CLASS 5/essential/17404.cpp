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

int n;
vector<vvi> dp(2, vvi(3, vi(3, INF)));

int main() {
	FASTIO;
	cin >> n;
	int a, b, c; cin >> a >> b >> c;
	dp[0][0][0] = a;
	dp[0][1][1] = b;
	dp[0][2][2] = c;
	n--;
	while (n--) {
		vi tmp(3);
		cin >> tmp[0] >> tmp[1] >> tmp[2];
		if (dp[0][1][0] != INF || dp[0][2][0] != INF)
			dp[1][0][0] = min(dp[0][1][0], dp[0][2][0]) + a;
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (dp[0][(i + 1) % 3][j] != INF || dp[0][(i + 2) % 3][j] != INF)
					dp[1][i][j] = min(dp[0][(i + 1) % 3][j], dp[0][(i + 2) % 3][j]) + tmp[i];
			}
		}
		// 출력 확인
		// for (int i = 0; i < dp.size(); i++) {
		// 	for (int j = 0; j < dp[i].size(); j++) {
		// 		cout << "|";
		// 		for (int k = 0; k < dp[i][j].size(); k++) {
		// 			cout << ((dp[i][j][k] == INF) ? 0 : dp[i][j][k]) << " ";
		// 		}
		// 		cout << "|";
		// 	}
		// 	cout << endl;
		// }
		// 옮기기
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				dp[0][i][j] = dp[1][i][j];
				dp[1][i][j] = INF;
			}
		}
	}
	int result = INF;
	for (int i = 0; i < 3; i++) {
		int tmp = min(dp[0][i][(i + 1) % 3], dp[0][i][(i + 2) % 3]);
		result = min(result, tmp);
	}
	cout << result;
}
