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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  for (int x = -999; x <= 999; x++) {
    for (int y = -999; y <= 999; y++) {
      if (a * x + b * y == c && d * x + e * y == f)
        cout << x << " " << y << endl;
    }
  }
}