#include <bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vi v;

int main() {
  int n, m;
  cin >> n >> m;
  while (n--) {
    int x;
    cin >> x;
    v.PB(x);
  }

  int maximum = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      for (int k = j + 1; k < v.size(); k++) {
        if (v[i] + v[j] + v[k] > m)
          continue;
        maximum = max(maximum, v[i] + v[j] + v[k]);
      }
    }
  }
  cout << maximum << endl;
}