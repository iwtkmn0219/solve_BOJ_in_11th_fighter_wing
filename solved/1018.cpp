#include <bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pi;

vs board;
string color = "WB";
int idx, tmp;

int main() {
	FASTIO;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		board.PB(s);
	}

	int answer = 64;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			tmp = 0;
			idx = 0;  // white start
			for (int r = 0; r < 8; r++) {
				for (int c = 0; c < 8; c++) {
					if (board[i + r][j + c] != color[idx]) {
						tmp++;
					}
					idx = (idx + 1) % 2;
				}
				idx = (idx + 1) % 2;
			}
			answer = min(answer, tmp);

			tmp = 0;
			idx = 1;  // black start
			for (int r = 0; r < 8; r++) {
				for (int c = 0; c < 8; c++) {
					if (board[i + r][j + c] != color[idx]) {
						tmp++;
					}
					idx = (idx + 1) % 2;
				}
				idx = (idx + 1) % 2;
			}
			answer = min(answer, tmp);
		}
	}
	cout << answer;
}