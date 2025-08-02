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
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; }
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
struct origami {
	int white, blue;
};

int n;
int result[2] = {0, 0};
vvi board;

bool chk_paper_color(int r, int rr, int c, int cc) {
	for (int i = r; i <= rr; i++)  {
		for (int j = c; j <= cc; j++) {
			if (board[i][j] != board[r][c]) {
				return false;
			}
		}
	}
	return true;
}

void recursion(int r, int rr, int c, int cc) {
	int status = chk_paper_color(r, rr, c, cc);
	// 섞인상태
	if (!status) {
		// 4
		recursion(r, (r + rr) / 2, c, (c + cc) / 2);
		// 3
		recursion((r + rr) / 2 + 1, rr, c, (c + cc) / 2);
		// 1
		recursion(r, (r + rr) / 2, (c + cc) / 2 + 1, cc);
		// 2
		recursion((r + rr) / 2 + 1, rr, (c + cc) / 2 + 1, cc);
	} else {
		result[board[r][c]]++;
	}
}

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vi tmpv;
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			tmpv.PB(tmp);
		}
		board.PB(tmpv);
	}
	recursion(0, n - 1, 0, n - 1);
	cout << result[0] << endl << result[1];
}
