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

int n, k;
vi dp, visited;
queue<int> q;

int main() {
	FASTIO;
	cin >> n >> k;
	if (n == k) {
		cout << 0;
	} else {
		const int MAX_SIZE = max(n, k) * 2;
		dp.resize(MAX_SIZE);
		visited.resize(MAX_SIZE);
		
		q.push(n);
		visited[n] = 1;
		while (!q.empty()) {
			int cp = q.front();
			NWATCH(cp);
			int tp = cp * 2;
			q.pop();
			while (tp < MAX_SIZE && tp > 0) {
				if (!visited[tp]) {
					visited[tp] = visited[cp];
					q.push(tp);
					tp *= 2;
				} else {
					break;
				}
			}
			if (cp - 1 >= 0 && !visited[cp - 1]) {
				visited[cp - 1] = visited[cp] + 1;
				q.push(cp - 1);
			}
			if (cp + 1 < MAX_SIZE && !visited[cp + 1]) {
				visited[cp + 1] = visited[cp] + 1;
				q.push(cp + 1);
			}
		}
		cout << visited[k] - 1;
	}
}
