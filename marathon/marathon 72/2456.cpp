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
struct Point {

};

int n;
vi score(3, 0);
vvi cnt(3, vi(3, 0));

int find_max(vi& v) {
	int value = 0;
	int result = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > value) {
			value = v[i];
			result = i;
		}
	}
	return result;
}

int count_element(vi& v, int x) {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == x) result++;
	}
	return result;
}

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		score[0] += a;
		score[1] += b;
		score[2] += c;
		cnt[3 - a][0]++;
		cnt[3 - b][1]++;
		cnt[3 - c][2]++;
	}
	if (count_element(score, score[find_max(score)]) == 1) {
		int idx = find_max(score);
		cout << idx + 1 << " " << score[idx];
	} else {
		for (int i = 0; i < 3; i++) {
			if (score[i] != score[find_max(score)]) {
				cnt[0][i] = 0;
				cnt[1][i] = 0;
				cnt[2][i] = 0;
			} else {
				cnt[0][i] += 10000;
				cnt[1][i] += 10000;
				cnt[2][i] += 10000;
			}
		}
		if (count_element(cnt[0], cnt[0][find_max(cnt[0])]) == 1) {
			int idx = find_max(cnt[0]);
			cout << idx + 1 << " " << score[idx];
		} else {
			for (int i = 0; i < 3; i++) {
				if (cnt[0][i] != cnt[0][find_max(score)]) {
					cnt[1][i] = 0;
					cnt[2][i] = 0;
				} else {
					cnt[1][i] += 10000;
					cnt[2][i] += 10000;
				}
			}
			if (count_element(cnt[1], cnt[1][find_max(cnt[1])]) == 1) {
				int idx = find_max(cnt[1]);
				cout << idx + 1 << " " << score[idx];
			} else {
				for (int i = 0; i < 3; i++) {
					if (cnt[1][i] != cnt[1][find_max(score)]) {
						cnt[2][i] = 0;
					} else {
						cnt[2][i] += 10000;
					}
				}
				int idx = find_max(cnt[2]);
				if (count_element(cnt[2], cnt[2][idx]) == 1) {
					cout << idx + 1 << " " << score[idx];
				} else {
					cout << 0 << " " << score[idx];
				}
			}
		}
	}
}
