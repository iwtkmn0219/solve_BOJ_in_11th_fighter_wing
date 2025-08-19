#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
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

string s1, s2;
stack<char> s;

int main() {
	FASTIO;
	cin >> s1 >> s2;
	int bomb_size = (int)s2.size();
	char end_char = s2[s2.size() - 1];
	for (auto word: s1) {
		// 일단 삽입
		s.push(word);
		NWATCH(word);

		if (s.size() < bomb_size) continue;

		if (word == end_char) {
			stack<char> tmps;
			for (int i = bomb_size - 1; i >= 0; i--) {
				if (s.empty() || s2[i] != s.top()) {
					// s가 비어있거나 값이 안맞으면
					while (!tmps.empty()) {
						s.push(tmps.top());
						tmps.pop();
					}
					break;
				} else {
					tmps.push(s.top());
					s.pop();
				}
			}
		}
	}

	if (s.empty()) {
		cout << "FRULA";
	} else {
		string result = "";
		while (!s.empty()) {
			result.PB(s.top());
			s.pop();
		}
		reverse(result.begin(), result.end());
		cout << result;
	}
}
