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
struct point {
	int x, y;
};

int n, r, c;

int recursion(int value, int newn, int rr, int cc) {
	NWATCH(rr);
	NWATCH(cc);
	// base case
	if (rr == r && cc == c) {
		return value;
	}

	int small_length = pow(2, newn - 1);
	int small_square_size = small_length * small_length;
	// 1 or 4
	if (r < rr + pow(2, newn - 1)) {
		// 4
		if (c < cc + pow(2, newn - 1)) {
			return recursion(value, newn - 1, rr, cc);
		}
		// 1
		else {
			return recursion(value + small_square_size, newn - 1, rr, cc + pow(2, newn - 1));
		}
	}
	// 2 or 3
	else {
		// 3
		if (c < cc + pow(2, newn - 1)) {
			return recursion(value + 2 * small_square_size, newn - 1, rr + pow(2, newn - 1), cc);
		}
		// 2
		else {
			return recursion(value + 3 * small_square_size, newn - 1, rr + pow(2, newn - 1), cc + pow(2, newn - 1));
		}
	}
}

int main() {
	FASTIO;
	cin >> n >> r >> c;
	cout << recursion(0, n, 0, 0);
}
