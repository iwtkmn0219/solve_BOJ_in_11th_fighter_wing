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

ll n, k;

ll count_less_or_equal(ll x) {
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		if (i * i <= x) cnt++; else break;
		ll start = i + 1, end = n;
		while (start + 1 < end) {
			ll mid = (start + end) / 2;
			ll value = mid * i;
			if (value <= x) {
				start = mid;
			} else {
				end = mid;
			}
		}
		if (start * i <= x && end * i <= x) {
			cnt += (end - i) * 2;
		} else if (start * i <= x) {
			cnt += (start - i) * 2;
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> n >> k;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	ll start = 1, end = n * n;
	while (start + 1 < end) {
		ll mid = (start + end) / 2;  // 중간값
		ll value = count_less_or_equal(mid);  // mid 이하의 개수
		NWATCH(mid);
		NWATCH(value);
		// value가 k보다 크거나 같아야 함
		if (value < k) {
			start = mid;
		} else {
			end = mid;
		}
	}
	cout << end;
}
