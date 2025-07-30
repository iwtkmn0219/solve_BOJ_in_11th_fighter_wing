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
vector<string> v1, v2, result;

int main() {
	FASTIO;
	cin >> n >> m;
	while (n--) {
		string tmp; cin >> tmp;
		v1.PB(tmp);
	}
	while (m--) {
		string tmp; cin >> tmp;
		v2.PB(tmp);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++) {
		// for (int j = 0; j < v1.size(); j++) {
		// 	if (v2[i] == v1[j]) {
		// 		result.PB(v2[i]);
		// 		break;
		// 	}
		// }
		// 이분탐색
		string value = v2[i];
		
		int s = 0;
		int e = v1.size() - 1;
		int m;
		while (s + 1 < e) {
			m = (s + e) / 2;
			if (v1[m] <= value) {
				s = m;
			} else if (v1[m] > value) {
				e = m;
			}
		}
		if (v1[s] == value || v1[e] == value) {
			result.PB(value);
		}
	}
	cout << result.size() << endl;
	for (auto& data: result) {
		cout << data << endl;
	}
}
