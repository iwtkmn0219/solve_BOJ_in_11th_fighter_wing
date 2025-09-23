#include <bits/stdc++.h>
#define endl "\n"
#define INF 2e9
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

int n, c, result = 0;
vi v;

int check_distance(int distance) {
	// cout << v[0] << " ";
	int tmp = INF;
	int selected = 0;
	for (int i = 0; i < c - 1; i++) {
		int s = selected, e = n;
		while (s + 1 < e) {
			int m = (s + e) / 2;
			if (v[m] - v[selected] < distance) {
				s = m;
			} else {
				e = m;
			}
		}
		if (v[e] == INF) {
			// cout << "INF!" << endl;
			return INF;
		} else {
			// cout << v[e] << " ";
			tmp = min(tmp, v[e] - v[selected]);
			selected = e;
		}
	}
	// cout << endl;
	return tmp;
}

int main() {
	FASTIO;
	cin >> n >> c;
	VINPUT(v, n);
	SORT(v);
	v.PB(INF);
	if (c == 2) {
		cout << v[n - 1] - v[0];
		return 0;
	}
	int mini = 0, maxi = v[n - 1];
	while (mini + 1 < maxi) {
		int midi = (mini + maxi) / 2;
		cout << mini << " " << maxi << " " << midi << endl;
		int distance = check_distance(midi);
		WATCH(distance);
		if (distance == INF) {  // 구성 불가한 경우 줄이기
			maxi = midi;
		} else {  // 구성 가능한 경우
			if (distance == midi) {
				result = max(result, midi);
			}
			if (distance >= midi) {
				mini = midi;
			} else {
				maxi = midi;
			}
		}
	}
	cout << result;
}
