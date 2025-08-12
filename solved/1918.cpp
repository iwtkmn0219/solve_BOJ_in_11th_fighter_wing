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

string p = "+", m = "-", mp = "*", dv = "/", open_em = "(", close_em = ")";
stack<string> words, signs;

void merge() {
	string beta = words.top();
	words.pop();
	string alpha = words.top();
	words.pop();
	string link = signs.top();
	signs.pop();
	words.push(alpha + beta + link);
}

int main() {
	// FASTIO;
	string line; cin >> line;
	int length = (int) line.size();
	for (int i = 0; i < length; i++) {
		NWATCH(line[i]);
		if (line[i] == open_em[0]) {
			signs.push(open_em);
		} else if (line[i] == close_em[0]) {
			while (!(signs.top() == open_em)) {
				merge();
			}
			signs.pop();
		} else if (line[i] == p[0] || line[i] == m[0]) {
			while (true) {
				if (signs.empty()) break;
				if (signs.top() == open_em) break;
				merge();
			}
			string tmp; tmp += line[i];
			signs.push(tmp);
		} else if (line[i] == mp[0] || line[i] == dv[0]) {
			while (true) {
				if (signs.empty()) break;
				if (signs.top() == open_em) break;
				if (signs.top() == p || signs.top() == m) {  // md -> pm
					break;
				} else {
					merge();
				}
			}
			string tmp; tmp += line[i];
			signs.push(tmp);
		} else {
			string tmp; tmp += line[i];
			words.push(tmp);
		}
	}

	while (!signs.empty()) {
		merge();
	}
	cout << words.top();
}
