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

string n8;

string n10ton2_3(int x, int len) {
	if (len == 3) return "";
	if (x == 0) return n10ton2_3(x, len + 1) + "0";
	return n10ton2_3(x / 2, len + 1) + to_string(x % 2);
}

int main() {
	FASTIO;
	cin >> n8;
	if (n8 == "0") {
		cout << n8;
	} else {
		string result = "";
		for (int i = 0; i < n8.size(); i++) {
			result += n10ton2_3(n8[i] - '0', 0);
			WATCH(result);
		}
		bool flag = false;
		for (int i = 0; i < result.size(); i++) {
			if (!flag) {
				if (result[i] == '1') {
					cout << result[i];
					flag = true;
				}
			} else {
				cout << result[i];
			}
		}
	}
}
