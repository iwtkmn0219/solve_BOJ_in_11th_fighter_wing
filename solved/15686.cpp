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
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; } cout << endl
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
	int row, col;
};

int n, m, d4[4][2] = dir4;
vvi board;
vector<point> chicken_point, house;
vvi closed_list;

void closed_list_init(int depth, int idx, vi v) {
	if (depth == m) {
		closed_list.PB(v);
		return;
	}
	if (idx >= chicken_point.size()) {
		return;
	}
	for (int i = idx; i < chicken_point.size(); i++) {
		v.PB(i);
		closed_list_init(depth + 1, i + 1, v);
		v.pop_back();
	}
}

int bfs(int row, int col) {
	queue<point> q;
	vvi visited(n, vi(n, 0));
	q.push({row, col});
	visited[row][col] = 1;
	while (!q.empty()) {
		int rr = q.front().row;
		int cc = q.front().col;
		q.pop();

		for (auto d: d4) {
			int nr = rr + d[0];
			int nc = cc + d[1];
			if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
				if (!visited[nr][nc]) {
					if (board[nr][nc] < 2) {
						visited[nr][nc] = visited[rr][cc] + 1;
						q.push({nr, nc});
					} else if (board[nr][nc] == 2) {
						return visited[rr][cc];
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> n >> m;
	
	board.resize(n, vi(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 2) {
				board[i][j] = 0;
				chicken_point.PB({i, j});
			} else if (tmp == 1) {
				house.PB({i, j});
			}
		}
	}
	// 치킨 집 개업하기
	vi tmpv;
	closed_list_init(0, 0, tmpv);

	int min_chicken_distance = INF;
	for (auto idx_list: closed_list) {
		int chicken_distance = 0;
		// VOUTPUT(idx_list);
		for (auto h: house) {
			int min_htoc = INF;
			for (auto idx: idx_list) {
				int chi_row = chicken_point[idx].row;
				int chi_col = chicken_point[idx].col;
				// board[chicken_point[idx].row][chicken_point[idx].col] = 2;
				int tmp = abs(h.row - chi_row) + abs(h.col - chi_col);
				min_htoc = min(min_htoc, tmp);
			}
			NWATCH(min_htoc);
			chicken_distance += min_htoc;
		}
		min_chicken_distance = min(min_chicken_distance, chicken_distance);
	}
	cout << min_chicken_distance;
}
