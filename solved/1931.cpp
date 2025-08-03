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
struct schedule {
	int start, end;
	bool operator<(const schedule &s) {
		if (end != s.end) return end < s.end;
		else return start < s.start;
	}
};

int n;
vector<schedule> v;

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		v.PB({tmp1, tmp2});
	}
	sort(v.begin(), v.end());

	int cnt = 1;
	int prev_end = v[0].end;
	for (int i = 1; i < n; i++) {
		// 회의를 시작할 수 있는 경우
		if (v[i].start >= prev_end) {
			// 회의 시작
			prev_end = v[i].end;
			cnt++;
		}
	}
	cout << cnt;
}
