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

int n, m;
vi v;
vvi pelindrom;

void init_pelindrom() {
	for (int i = 1; i <= n; i++) {
		int start = i, end = i;
		while (start >= 1 && end <= n) {
			if (v[start] == v[end]) {
				pelindrom[start--][end++] = true;
			} else {
				break;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		int start = i, end = i + 1;
		while (start >= 1 && end <= n) {
			if (v[start] == v[end]) {
				pelindrom[start--][end++] = true;
			} else {
				break;
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> n;
	pelindrom.resize(n + 1, vi(n + 1, 0));
	v.PB(0);
	VINPUT(v, n);
	init_pelindrom();
	cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		cout << pelindrom[a][b] << endl;
	}
}
