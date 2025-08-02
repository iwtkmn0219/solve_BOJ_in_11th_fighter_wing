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

int find_666(int x) {
	while (x >= 666) {
		if (x % 1000 == 666) {
			return 1;
		}
		x /= 10;
	}
	return 0;
}

int main() {
	FASTIO;
	int n, i = 666;
	cin >> n;
	while (n) {
		if (find_666(i++) == 1) {
			n--;
		}
	}
	cout << i - 1;
}