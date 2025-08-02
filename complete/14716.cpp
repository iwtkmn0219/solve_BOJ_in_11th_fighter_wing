#include <bits/stdc++.h>
#define INF 1e9
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; }
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; }
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pi;

int n, m;
vector<vi> board;
vector<vi> visited(250, vi (250, 0));
struct point {
	int x, y;
};
queue<point> q;

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void bfs(point p) {
	visited[p.x][p.y] = 1;
	q.push(p);
	while (!q.empty()) {
		int rr = q.front().x;
		int cc = q.front().y;
		q.pop();
		REP(i, 0, 8) {
			int nr = rr + dir[i][0];
			int nc = cc + dir[i][1];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				if (board[nr][nc] && !visited[nr][nc]) {
					visited[nr][nc] = 1;
					q.push({nr, nc});
				}
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> n >> m;
	REP(i, 0, n) {
		vi tmpv;
		REP(j, 0, m) {
			int tmp; cin >> tmp;
			tmpv.PB(tmp);
		}
		board.PB(tmpv);
	}

	// bfs
	int sum = 0;
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (board[i][j] && !visited[i][j]) {
				bfs({i, j});
				sum++;
			}
		}
	}
	cout << sum;
}