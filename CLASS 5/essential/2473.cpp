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

int n;
vector<ll> v;

int main() {
	FASTIO;
	// 우선 정렬을 하고
	// 원소 두개 고르고
	// 이분탐색 할거임
	cin >> n;
	VINPUT(v, n);
	SORT(v);
	ll density = 5e9;
	vector<ll> result(3, 0);
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			ll mix = v[i] + v[j];
			int s = j + 1, e = n - 1;
			while (s + 1 < e) {
				int m = (s + e) / 2;
				if (mix + v[m] >= 0) e = m;
				else s = m;
			}
			if (abs(v[s] + mix) > abs(v[e] + mix)) {
				if (abs(v[e] + mix) < abs(density)) {
					density = v[e] + mix;
					result[0] = v[i];
					result[1] = v[j];
					result[2] = v[e];
				}
			} else {
				if (abs(v[s] + mix) < abs(density)) {
					density = v[s] + mix;
					result[0] = v[i];
					result[1] = v[j];
					result[2] = v[s];
				}
			}
		}
	}
	VOUTPUT(result);
}
