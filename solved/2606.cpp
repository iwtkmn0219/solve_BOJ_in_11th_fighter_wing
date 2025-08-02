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

int x, n;

int main() {
	// FASTIO;
	cin >> x;
	cin >> n;
	vvi graph(x + 1, vi(x + 1, 0));
	for (int i = 0; i < n; i++) {
		int n1, n2; cin >> n1 >> n2;
		graph[n1][n2] = 1;
		graph[n2][n1] = 1;
	}
	int cnt = 0;
	queue<int> q;
	vi visit(x + 1, 0);
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 1 ; i <= x; i++) {
			if (graph[front][i] && !visit[i]) {
				q.push(i);
				visit[i] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;
}
