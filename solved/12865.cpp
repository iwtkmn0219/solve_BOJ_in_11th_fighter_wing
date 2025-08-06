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
struct object {
	int weight, value;
	bool operator<(const object &o) {
		if (weight != o.weight) return weight < o.weight;
		else return value > o.value;
	}
};

int n, k;
vector<object> vo;
vvi dp;

int main() {
	FASTIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		vo.PB({tmp1, tmp2});
	}
	dp.resize(n, vi(k + 1));
	sort(vo.begin(), vo.end());
	if (vo[0].weight <= k) {
		dp[0][vo[0].weight] = vo[0].value;
	}
	for (int i = 1; i < n; i++) {
		object tmp = vo[i];
		for (int j = 0; j <= k; j++) {
			if (j + tmp.weight <= k && (j == 0 || dp[i - 1][j] > 0)) {
				dp[i][j + tmp.weight] = max(dp[i - 1][j + tmp.weight], dp[i - 1][j] + tmp.value);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	
	int maximum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			maximum = max(maximum, dp[i][j]);
		}
	}
	// V2DOUTPUT(dp);
	cout << maximum;
}
