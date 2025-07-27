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

int n, m, r, c;
vvi real_height, blue_print;

int main() {
	FASTIO;
	cin >> n >> m >> r >> c;
	V2DINPUT(real_height, n, m);
	V2DINPUT(blue_print, r, c);
	int cnt = 0;
	REP(i, 0, n - r + 1) {
		REP(j, 0, m - c + 1) {
			int standard = real_height[i][j] - blue_print[0][0];

			bool flag = true;
			REP(k, 0, blue_print.size()) {
				REP(h, 0, blue_print[0].size()) {
					int tmp = real_height[i + k][j + h] - blue_print[k][h];
					if (tmp != standard) {
						flag = false;
					}
				}
			}

			cnt += flag ? 1 : 0;
		}
	}
	cout << cnt;
}
