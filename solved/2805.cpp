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

int n, m;
vector<ll> v;

ll my_tree(int height) {
	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (v[i] > height) ? v[i] - height : 0;
	}
	return sum;
}

int main() {
	FASTIO;
	cin >> n >> m;
	ll maximum_height = 0;
	for (int i = 0; i < n; i++) {
		ll tmp; cin >> tmp;
		v.PB(tmp);
		maximum_height = max(maximum_height, tmp);
	}

	ll s = 0, e = maximum_height + 1, mid;
	while (s + 1 < e) {
		mid = (s + e) / 2;
		ll result = my_tree(mid);

		if (result >= m) {
			s = mid;
		} else if (result < m) {
			e = mid;
		}
	}
	cout << s;
}
