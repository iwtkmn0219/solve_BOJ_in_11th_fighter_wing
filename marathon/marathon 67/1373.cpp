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

string s, result = "";

int main() {
	FASTIO;
	cin >> s;
	int s_size = (int)s.size();
	REV(s);
	for (int i = 0; i < (s_size / 3 + 1) * 3 - s_size; i++) {
		s += "0";
	}
	int tmp = 0;
	for (int i = 0; i < s.size(); i++) {
		int idx = i % 3;
		int num = s[i] - '0';
		for (int j = 0; j < idx; j++) {
			num *= 2;
		}
		tmp += num;
		if (idx == 2) {
			result += to_string(tmp);
			tmp = 0;
		}
	}
	REV(result);
	WATCH(result);
	bool flag = false;
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) {
			cout << result[i];
			break;
		}
		if (!flag) {
			if (result[i] != '0') {
				flag = true;
				cout << result[i];
			}
		} else {
			cout << result[i];
		}
	}
}
