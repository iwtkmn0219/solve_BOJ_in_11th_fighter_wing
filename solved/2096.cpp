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

int n, a, b, c;
vector<vvi> board(2, vvi(3, vi(2, 0)));

int main() {
	FASTIO;
	cin >> n;
	cin >> a >> b >> c;
	board[0][0][0] = a;
	board[0][0][1] = a;
	board[0][1][0] = b;
	board[0][1][1] = b;
	board[0][2][0] = c;
	board[0][2][1] = c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		board[1][0][0] = max(board[0][0][0], board[0][1][0]) + a;
		board[1][0][1] = min(board[0][0][1], board[0][1][1]) + a;
		board[1][1][0] = max(board[0][0][0], max(board[0][1][0], board[0][2][0])) + b;
		board[1][1][1] = min(board[0][0][1], min(board[0][1][1], board[0][2][1])) + b;
		board[1][2][0] = max(board[0][1][0], board[0][2][0]) + c;
		board[1][2][1] = min(board[0][1][1], board[0][2][1]) + c;

		for (int i = 0; i < 3; i++) {
			board[0][i][0] = board[1][i][0];
			board[0][i][1] = board[1][i][1];
		}

		NV2DOUTPUT(board[0]);
	}

	int maxi = max(board[0][0][0], max(board[0][1][0], board[0][2][0]));
	int mini = min(board[0][0][1], min(board[0][1][1], board[0][2][1]));
	cout << maxi << " " << mini;
}
