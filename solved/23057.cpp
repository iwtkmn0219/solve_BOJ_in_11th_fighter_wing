#include <bits/stdc++.h>
#define INF 1e9
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

set<int> s;
int n;
vi v;

void recursion(int max_depth, int depth, int idx, int sum) {
	if (depth == max_depth) {
		s.insert(sum);
		return;
	}
	if (idx == n) {
		return;
	}
	REP(i, idx, n) {
		recursion(max_depth, depth + 1, i + 1, sum + v[i]);
	}
}

int main() {
	FASTIO;
	cin >> n;
	int maximum = 0;
	REP(i, 0, n) {
		int tmp; cin >> tmp;
		v.PB(tmp);
		maximum += tmp;
	}

	REP(i, 1, n + 1) {
		recursion(i, 0, 0, 0);
	}

	cout << maximum - s.size();
}