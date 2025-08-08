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

string s1, s2;
vvi dp2;

int main() {
	FASTIO;
	cin >> s1 >> s2;
	dp2.resize((int)s2.size() + 1, vi((int)s1.size() + 1, 0));
	for (int i = 1; i < dp2.size(); i++) {
		for (int j = 1; j < dp2[i].size(); j++) {
			if (s2[i - 1] == s1[j - 1]) {
				dp2[i][j] = max(dp2[i - 1][j - 1] + 1, dp2[i][j - 1]);
			} else {
				dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
			}
		}
	}
	V2DOUTPUT(dp2);
	cout << dp2[dp2.size() - 1][dp2[0].size() - 1];
}
