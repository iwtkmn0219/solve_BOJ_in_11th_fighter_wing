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
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << ; } cout << endl; }
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

ll n, m;
vector<ll> prime_vector(1000001, 1);
set<ll> s;

void prime_number() {
	for (int i = 2; i * i <= 1000000; i++) {
		if (prime_vector[i] == 0) continue;
		for (ll j = i * i; j <= 1000000; j += i) {
			prime_vector[j] = 0;
		}
	}
	for (ll i = 2; i <= 1000000; i++) {
		if (prime_vector[i]) {
			s.insert(i * i);
		}
	}
}

int main() {
	FASTIO;
	prime_number();
	cin >> n >> m;
	vector<ll> used(m - n + 1, 1);
	for (auto itor = s.begin(); itor != s.end(); itor++) {
		ll tmp_value = (ceil((double) n / (double)(*itor))) * (*itor);
		while (tmp_value <= m) {
			used[tmp_value - n] = 0;
			tmp_value += *itor;
		}
	}
	ll cnt = 0;
	REP(i, 0, used.size()) {
		cnt += used[i];
	}
	// VOUTPUT(used);
	cout << cnt;
}
