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

int sqrt3(int x) {
	int k = 3;
	for (int i = 1; i < 8; i++) {
		if (k == x) return i;
		k *= 3;
	}
	return 0;
}

string switch_white_space(string s) {
	string result = "";
	for (auto word: s) {
		result += " ";
	}
	return result;
}

void recursion(int x, int record) {
	if (x == 0) {
		// base case (record 해석)
		string result = "*";
		for (int i = 1; i <= sqrt3(n); i++) {
			if (record & (1 << i)) {
				result += result + result;
			} else {
				result += switch_white_space(result) + result;
			}
		}
		cout << result << endl;
		return;
	}
	recursion(x - 1, record | (1 << x));
	recursion(x - 1, record);
	recursion(x - 1, record | (1 << x));
}

int main() {
	FASTIO;
	cin >> n;
	recursion(sqrt3(n), 0);
}
