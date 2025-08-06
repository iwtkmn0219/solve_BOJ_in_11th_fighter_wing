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
struct child {
	string c1, c2;
};

int n;
map<string, child> tree;

void preorder(string node) {
	cout << node;
	if (tree[node].c1 != ".") preorder(tree[node].c1);
	if (tree[node].c2 != ".") preorder(tree[node].c2);
}

void inorder(string node) {
	if (tree[node].c1 != ".") inorder(tree[node].c1);
	cout << node;
	if (tree[node].c2 != ".") inorder(tree[node].c2);
}

void postorder(string node) {
	if (tree[node].c1 != ".") postorder(tree[node].c1);
	if (tree[node].c2 != ".") postorder(tree[node].c2);
	cout << node;
}

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string parrent, child1, child2; cin >> parrent >> child1 >> child2;
		tree[parrent].c1 = child1;
		tree[parrent].c2 = child2;
	}
	preorder("A");
	cout << endl;
	inorder("A");
	cout << endl;
	postorder("A");
}
