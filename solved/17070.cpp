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
struct Pipe {
	int row, col, direction;
};

int n;
vector<vvi> dir = {{{0, 1}, {1, 1}}, {{0, 1}, {1, 1}, {1, 0}}, {{1, 1}, {1, 0}}};
vvi board;
vector<vvi> dp_table(16, vvi(16, vi(3, 0)));

int dp() {
	dp_table[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (i == 0) {
				if (j == 1) continue;
				if (board[i][j] == 0)
					dp_table[i][j][0] = dp_table[i][j - 1][0];
			} else {
				if (board[i][j] == 0) {
					if (!board[i - 1][j] && !board[i][j - 1]) {
						dp_table[i][j][1] = dp_table[i - 1][j - 1][0] + dp_table[i - 1][j - 1][1] + dp_table[i - 1][j - 1][2];
					}
					dp_table[i][j][0] = dp_table[i][j - 1][0] + dp_table[i][j - 1][1];
					dp_table[i][j][2] = dp_table[i - 1][j][2] + dp_table[i - 1][j][1];
				}
			}
		}
	}
	return dp_table[n - 1][n - 1][0] + dp_table[n - 1][n - 1][1] + dp_table[n - 1][n - 1][2];
}

int main() {
	FASTIO;
	cin >> n;
	V2DINPUT(board, n, n);
	cout << dp();
}
