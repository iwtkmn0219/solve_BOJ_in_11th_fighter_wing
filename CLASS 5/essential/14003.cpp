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

const int BEDROCK = -1111111111;
int n;
vi v, parrent;
vector<pi> result;

int binary_search(int start, int end, int value) {
	while (start + 1 < end) {
		int mid = (start + end) / 2;
		if (result[mid].F >= value) end = mid;
		else start = mid;
	}
	return end;
}

void print_lis(int idx) {
	vi lis;
	while (idx > 0) {
		lis.PB(v[idx]);
		idx = parrent[idx];
	}
	REV(lis);
	VOUTPUT(lis);
}

int main() {
	FASTIO;
	cin >> n;
	parrent.resize(n + 1, 0);
	v.PB(BEDROCK);
	VINPUT(v, n);
	result.PB({BEDROCK, 0});
	for (int i = 1; i < v.size(); i++) {
		int value = v[i];
		if (value > result[result.size() - 1].F) {
			int parrent_idx = result[result.size() - 1].S;
			parrent[i] = parrent_idx;
			result.PB({value, i});
		} else {
			int idx = binary_search(0, result.size(), value);
			int parrent_idx = result[idx - 1].S;
			parrent[i] = parrent_idx;
			result[idx] = {value, i};
		}
	}
	cout << result.size() - 1 << endl;
	print_lis(result[result.size() - 1].S);
}
