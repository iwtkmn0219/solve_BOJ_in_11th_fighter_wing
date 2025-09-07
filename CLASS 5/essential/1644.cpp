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
struct point {
	int x, y;
};

vi prime_number(4000001, 1);
vi prime_numbers;
vi pre_sum;

void init_prime_number() {
	for (int i = 2; i <= sqrt(4000000); i++) {
		if (prime_number[i] == 0) continue;
		for (int j = i * i; j <= 4000000; j += i) {
			prime_number[j] = 0;
		}
	}
	for (int i = 2; i <= 4000000; i++) {
		if (prime_number[i] == 1) prime_numbers.PB(i);
	}
}

int n;

int main() {
	FASTIO;
	init_prime_number();
	pre_sum.PB(0);
	for (int i = 0; i < prime_numbers.size(); i++) {
		pre_sum.PB(prime_numbers[i] + pre_sum[i]);
	}
	cin >> n;
	int s = 1, e = 1, result = 0;
	while (s < pre_sum.size()) {
		int tmp_sum = pre_sum[e] - pre_sum[s - 1];
		if (tmp_sum == n) {
			result++;
			e++;
		} else if (tmp_sum > n) {
			if (s == e) {
				e++;
			} else {
				s++;
			}
		} else {
			e++;
		}
	}
	cout << result;
}
