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
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; } cout << endl;
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
	int row, col, dis;
};

struct compare {
	bool operator()(const point &p1, const point &p2) {
		if (p1.row != p2.row) return p1.row > p2.row;
		else return p1.col > p2.col;
	}
};

int n, d4[4][2] = dir4;
vvi board;

point bfs(int row, int col, int s_size) {
	priority_queue<point, vector<point>, compare> pq;
	vvi visited(n, vi(n, 0));
	int min_dis= INF;
	queue<point> q;
	q.push({row, col, 0});
	visited[row][col] = 1;
	while (!q.empty()) {
		int rr = q.front().row;
		int cc = q.front().col;
		q.pop();
		if (visited[rr][cc] >= min_dis) continue;
		for (auto d: d4) {
			int nr = rr + d[0];
			int nc = cc + d[1];
			if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
				if (!visited[nr][nc]) {
					if (board[nr][nc] > s_size) {
						// 못지나감
						continue;
					}
					
					if (board[nr][nc] == s_size || board[nr][nc] == 0) {
						// 지나가기만 함
						q.push({nr, nc, visited[rr][cc]});
						visited[nr][nc] = visited[rr][cc] + 1;
					} else {
						// 먹을 수 있음
						if (min_dis == INF) {
							min_dis = visited[rr][cc] + 1;
							visited[nr][nc] = visited[rr][cc] + 1;
							pq.push({nr, nc, visited[rr][cc]});
						} else {
							if (visited[rr][cc] + 1 == min_dis) {
								visited[nr][nc] = visited[rr][cc] + 1;
								pq.push({nr, nc, visited[rr][cc]});
							}
						}
					}
				}
			}
		}
	}
	NV2DOUTPUT(visited);
	if (pq.empty()) {
		return {-1, -1, -1};
	} else {
		return pq.top();
	}
}

int main() {
	FASTIO;
	cin >> n;
	V2DINPUT(board, n, n);
	int sr, sc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 9) {
				sr = i;
				sc = j;
			}
		}
	}

	int shark_size = 2;
	int shark_stomach = 0;
	int result = 0;
	while (true) {
		NV2DOUTPUT(board);
		point tmp = bfs(sr, sc, shark_size);
		if (tmp.row == -1) {
			break;
		} else {
			result += tmp.dis;
			board[sr][sc] = 0;
			sr = tmp.row;
			sc = tmp.col;
			board[sr][sc] = 0;
			shark_stomach++;
			if (shark_stomach == shark_size) {
				shark_size++;
				shark_stomach = 0;
			}
		}
	}
	cout << result;
}
