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

int tc, f;

int find(vi& v, int x) {
	if (v[x] == x) return x;
	return find(v, v[x]);
}

void union_parrent(vi& v, vi& count, int x, int y) {
	x = find(v, x);
	y = find(v, y);
	if (x < y) {
		v[y] = x;
		count[x] += count[y];
	} else if (x > y) {
		v[x] = y;
		count[y] += count[x];
	}
}

int main() {
	FASTIO;
	cin >> tc;
	while (tc--) {
		map<string, int> m;
		vi parrent;
		vi count;
		cin >> f;
		while (f--) {
			string p1, p2; cin >> p1 >> p2;
			if (m.find(p1) == m.end()) {
				m[p1] = parrent.size();
				parrent.PB(parrent.size());
				count.PB(1);
			}
			if (m.find(p2) == m.end()) {
				m[p2] = parrent.size();
				parrent.PB(parrent.size());
				count.PB(1);
			}
			union_parrent(parrent, count, m[p1], m[p2]);
			NVOUTPUT(parrent);
			NVOUTPUT(count);
			cout << count[find(parrent, m[p1])] << endl;
		}
	}
}
