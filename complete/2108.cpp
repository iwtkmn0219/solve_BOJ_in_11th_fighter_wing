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

int n;
vi v, chk_sort(8001, 0);

int main() {
	FASTIO;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.PB(tmp);
		sum += tmp;
		chk_sort[tmp + 4000]++;
	}
	int maxi = 0;
	int arr[2] = {-1, -1};
	for (int i = 0; i < chk_sort.size(); i++) {
		if (chk_sort[i] > maxi) {
			arr[0] = i;
			arr[1] = -1;
			maxi = chk_sort[i];
		} else if (chk_sort[i] == maxi) {
			if (arr[1] == -1) {
				arr[1] = i;
			}
		} else {
			continue;
		}
	}
	sort(v.begin(), v.end());
	int avg = round((double) sum / (double) n);
	cout << avg << endl;
	cout << v[n / 2] << endl;
	cout << max(arr[0], arr[1]) - 4000 << endl;
	cout << v[n - 1] - v[0] << endl;
}
