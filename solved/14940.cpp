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
struct axis {
	int r, c;
};

int n, m;
int direction[4][2] = dir4;
vvi board, visited;
queue<axis> q;

int main() {
	FASTIO;
	cin >> n >> m;
	board.resize(n, vi(m + 1, 0));
	visited.resize(n, vi(m + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp; cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 2) {
				q.push({i, j});
				visited[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + direction[i][0];
			int nc = c + direction[i][1];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				if (board[nr][nc] > 0 && !visited[nr][nc]) {
					q.push({nr, nc});
					visited[nr][nc] = visited[r][c] + 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 원래 갈 수 없는 땅
			if (board[i][j] == 0) {
				cout << 0;
			}
			// 갈 수 있는 땅인데 도달할 수 없는 위치
			else if (visited[i][j] == 0) {
				cout << -1;
			} else {
				cout << visited[i][j] - 1;
			}
			cout << " ";
		}
		cout << endl;
	}
}
