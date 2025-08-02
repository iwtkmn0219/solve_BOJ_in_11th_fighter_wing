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
typedef pair<int, int> pi;

int main() {
  FASTIO;

  int n;
  cin >> n;
  REP(i, 1, n) {
    int sum = i;
    int j = i;
    while (j > 0) {
      sum += j % 10;
      j /= 10;
    }
    if (sum == n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
}