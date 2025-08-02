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
	ll x, y;
};

int n;
vector<point> v;
vector<vector<int>> comb_result;

void combination() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vi tmpv;
			tmpv.PB(i);
			tmpv.PB(j);
			comb_result.PB(tmpv);
		}
	}
}

int main() {
	FASTIO;
	cin >> n;
	REP(i, 0, n) {
		ll t1, t2; cin >> t1 >> t2;
		v.PB({t1, t2});
	}
	vi tmpv;
	combination();  // 가능한 경우의 수
	ll result = 5 * INF * INF;
	// 최대 1225번
	for (int i = 0; i < comb_result.size(); i++) {
		ll minx = INF, maxx = -INF, miny = INF, maxy = -INF;
		// 최대 2
		for (int j = 0; j < n; j++) {
			if (j == comb_result[i][0] || j == comb_result[i][1]) {
				continue;
			}
			NWATCH(j);
			minx = min(minx, v[j].x);
			maxx = max(maxx, v[j].x);
			miny = min(miny, v[j].y);
			maxy = max(maxy, v[j].y);
		}
		ll square_length = max(maxx - minx, maxy - miny) + 2;
		NWATCH(square_length);
		result = min(result, square_length * square_length);
	}
	cout << result;
}
