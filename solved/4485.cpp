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
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; }
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
	int dis, row, col;
};

struct compare {
	bool operator()(const point &p1, const point &p2) {
		if (p1.dis != p2.dis) return p1.dis > p2.dis;
		else if (p1.row != p2.row) return p1.row < p2.row;
		else return p1.col < p2.col;
	}
};

int n, d4[4][2] = dir4;
// priority_queue<point, vector<point>, compare> pq;
priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;

int main() {
	FASTIO;
	int tc = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		vvi board;
		vvi visited(n, vi(n, INF));
		V2DINPUT(board, n, n);

		pq.push({board[0][0], {0, 0}});
		visited[0][0] = board[0][0];
		while (!pq.empty()) {
			int rr = pq.top().S.F;
			int cc = pq.top().S.S;
			int dis = pq.top().F;
			NWATCH(board[rr][cc]);
			pq.pop();
			if (visited[rr][cc] < dis) continue;
			for (auto d: d4) {
				int nr = rr + d[0];
				int nc = cc + d[1];
				if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
					int ndis = dis + board[nr][nc];
					if (ndis >= visited[n - 1][n - 1]) continue;
					if (ndis < visited[nr][nc]) {
						visited[nr][nc] = ndis;
						pq.push({ndis, {nr, nc}});
					}
				}
			}
		}
		NV2DOUTPUT(visited);
		cout << "Problem " << tc++ << ": " << visited[n - 1][n - 1] << endl;
	}
}
