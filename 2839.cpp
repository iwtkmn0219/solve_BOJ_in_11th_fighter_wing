#include <bits/stdc++.h>
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

int main() {
	int n; cin >> n;
	int answer = 1e9;
	for (int i = 0; i <= n / 3; i++) {
		if ((n - i * 3) % 5 == 0) {
			answer = min(answer, i + (n - i * 3) / 5);
		}
	}
	cout << ((answer == 1e9) ? -1 : answer);
}