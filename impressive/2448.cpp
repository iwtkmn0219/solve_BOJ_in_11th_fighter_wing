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

int n, k;
const string STAR = "  *  \n * * \n*****";

void print_star(string star_code) {
	for (auto sc: star_code) {
		if (sc == '0') {
			cout << "   ";
		} else {
			cout << "  *   ";
		}
	}
	cout << endl;
	for (auto sc: star_code) {
		if (sc == '0') {
			cout << "   ";
		} else {
			cout << " * *  ";
		}
	}
	cout << endl;
	for (auto sc: star_code) {
		if (sc == '0') {
			cout << "   ";
		} else {
			cout << "***** ";
		}
	}
	cout << endl;
}

void recursion(int depth, int visited) {
	if (depth < 0) {
		string result = "1";
		for (int i = 0; i < k; i++) {
			if (visited & (1 << i)) {
				for (int j = 0; j < (1 << i); j++) {
					result = "0" + result + "0";
				}
			} else {
				result = result + result;
			}
		}
		NWATCH(result);
		print_star(result);
		return;
	}
	recursion(depth - 1, visited | (1 << depth));
	recursion(depth - 1, visited);
}

int main() {
	FASTIO;
	cin >> n;
	k = log2(n / 3);
	recursion(k - 1, 0);
}
