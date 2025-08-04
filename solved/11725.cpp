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

int n;
vi result;
vvi board;
queue<int> q;

int main() {
	FASTIO;
	cin >> n;
	result.resize(n + 1, 0);
	board.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int node1, node2; cin >> node1 >> node2;
		board[node1].PB(node2);
		board[node2].PB(node1);
	}

	q.push(1);
	result[1] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < board[current].size(); i++) {
			int next = board[current][i];
			if (!result[next]) {
				q.push(next);
				result[next] = current;
			}
		}
	}
	for (int i = 2; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}
