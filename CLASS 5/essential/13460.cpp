#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define board_condition(row, col, n, m) (row >= 0 && row < n && col >= 0 && col < m)
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REV(x) reverse(x.begin(), x.end())
#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; } cout << endl
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; } cout << endl
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
struct Mem {
	int rr, rc, br, bc, count;
};

int n, m;
int d4[4][2] = dir4;
vector<string> board;

void move(int& cr, int& cc, int& distance, int i) {
	while (board[cr + d4[i][0]][cc + d4[i][1]] != '#' && board[cr][cc] != 'O') {
		cr += d4[i][0];
		cc += d4[i][1];
		distance++;
	}
}

void bfs(int rr, int rc, int br, int bc) {
	queue<Mem> q;
	q.push({rr, rc, br, bc, 0});
	while (!q.empty()) {
		int rr = q.front().rr;
		int rc = q.front().rc;
		int br = q.front().br;
		int bc = q.front().bc;
		int count = q.front().count;
		q.pop();
		// cout << rr << " " << rc << " " << br << " " << bc << endl;
		if (count >= 10) {
			cout << -1;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nrr = rr;
			int nrc = rc;
			int nbr = br;
			int nbc = bc;
			int red_dis = 0, blue_dis = 0;
			move(nrr, nrc, red_dis, i);
			move(nbr, nbc, blue_dis, i);
			if (board[nbr][nbc] == 'O') continue;
			if (board[nrr][nrc] == 'O') {
				cout << count + 1;
				return ;
			}

			if (nrr == nbr && nrc == nbc) {
				if (red_dis >= blue_dis) {
					nrr -= d4[i][0];
					nrc -= d4[i][1];
				} else {
					nbr -= d4[i][0];
					nbc -= d4[i][1];
				}
			}
			// cout << nrr << " " << nrc << " " << nbr << " " << nbc << endl;
			q.push({nrr, nrc, nbr, nbc, count + 1});
		}
	}
}

int main() {
	// FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		board.PB(tmp);
	}
	int red_row, red_col, blue_row, blue_col;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				red_row = i;
				red_col = j;
			} else if (board[i][j] == 'B') {
				blue_row = i;
				blue_col = j;
			}
		}
	}
	bfs(red_row, red_col, blue_row, blue_col);
}
