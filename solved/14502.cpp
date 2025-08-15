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

int n, m;
int d4[4][2] = dir4;
vvi board;

vector<point> zero_point;
vector<point> virus_point;



int main() {
	FASTIO;
	cin >> n >> m;
	board.resize(n, vi(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp; cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 0) {
				zero_point.PB({i, j});
			} else if (tmp == 2) {
				virus_point.PB({i, j});
			}
		}
	}

	int max_result = 0;
	for (int i = 0; i < zero_point.size(); i++) {
		for (int j = i + 1; j < zero_point.size(); j++) {
			for (int k = j + 1; k < zero_point.size(); k++) {
				// 마킹
				board[zero_point[i].row][zero_point[i].col] = 1;
				board[zero_point[j].row][zero_point[j].col] = 1;
				board[zero_point[k].row][zero_point[k].col] = 1;

				// 바이러스 확산
				queue<point> q;
				vvi visited(n, vi(m, 0));
				for (auto vpoint: virus_point) {
					q.push(vpoint);
					visited[vpoint.row][vpoint.col] = 2;
				}
				while (!q.empty()) {
					int rr = q.front().row;
					int cc = q.front().col;
					q.pop();
					for (auto d: d4) {
						int nr = rr + d[0];
						int nc = cc + d[1];
						if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
							if (board[nr][nc] == 0 && !visited[nr][nc]) {
								visited[nr][nc] = 2;
								q.push({nr, nc});
							}
						}
					}
				}

				// 빈공간 확인
				int result = 0;
				for (int r = 0; r < n; r++)  {
					for (int c = 0; c < m; c++) {
						if (board[r][c] == 0 && !visited[r][c]) {
							q.push({r, c});
							visited[r][c] = 1;
							while (!q.empty()) {
								result++;
								int rr = q.front().row;
								int cc = q.front().col;
								q.pop();
								for (auto d: d4) {
									int nr = rr + d[0];
									int nc = cc + d[1];
									if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
										if (board[nr][nc] == 0 && !visited[nr][nc]) {
											visited[nr][nc] = 1;
											q.push({nr, nc});
										}
									}
								}
							}
						}
					}
				}
				// V2DOUTPUT(board);
				// V2DOUTPUT(visited);
				// WATCH(result);

				// 최대 크기 업데이트
				max_result = max(max_result, result);

				// 마킹 해제
				board[zero_point[i].row][zero_point[i].col] = 0;
				board[zero_point[j].row][zero_point[j].col] = 0;
				board[zero_point[k].row][zero_point[k].col] = 0;
			}
		}
	}
	cout << max_result;
}
