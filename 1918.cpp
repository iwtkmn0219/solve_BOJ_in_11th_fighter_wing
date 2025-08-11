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

int main() {
	FASTIO;
	string question; cin >> question;
	string result = "";
	question = "(" + question + ")";
	stack<string> alphabet, sign;
	stack<int> prev;

	int pm = 0, md = 0;

	for (int i = 0; i < question.size(); i++) {
		char word = question[i];
		if (word == '(') {
			
		} else if (word == ')') {
			string second = alphabet.top();
			alphabet.pop();
			string first = alphabet.top();
			alphabet.pop();
			string third = sign.top();
			sign.pop();
			string tmp_result = first + second + third;
			alphabet.push(tmp_result);
		} else if (word == '+' || word == '-' || word == '*' || word == '/') {
			string tmp; tmp += word;
			sign.push(tmp);
		} else {
			string tmp; tmp += word;
			alphabet.push(tmp);
		}
	}
	cout << alphabet.top();
}
