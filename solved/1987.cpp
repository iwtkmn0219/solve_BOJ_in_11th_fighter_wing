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
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; } cout << endl
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
	int row, col, used, dis;
};

int n, m, d4[4][2] = dir4;
vector<string> board;
int maxdis = 0;
void dfs(int rr, int cc, int used, int dis) {
	NWATCH(board[rr][cc]);
	maxdis = max(maxdis, dis);
	for (auto d: d4) {
		int nr = rr + d[0];
		int nc = cc + d[1];
		if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
			if (!(used & (1 << (board[nr][nc] - 'A')))) {
				dfs(nr, nc, (used | (1 << (board[nr][nc] - 'A'))), dis + 1);
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		board.PB(tmp);
	}
	dfs(0, 0, (1 << (board[0][0] - 'A')), 1);
	cout << maxdis;
}
