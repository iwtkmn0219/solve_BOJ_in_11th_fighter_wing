#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define board_condition(row, col, n, m) (row >= 0 && row < n && col >= 0 && col < m)
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REV(x) reverse(x.begin(), x.end())
#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }
#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; } cout << endl
#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }
#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; } cout << endl
#define WATCH(x) cout << #x << " : " << x << endl
#define DEBUG(x) cout << "DB - " << x << endl
#define PRINT(x) cout <<  x << endl
#define NVOUTPUT(x)
#define NV2DOUTPUT(x)
#define NWATCH(x)
#define NDEBUG(x)
#define NPRINT(x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pi;
struct node {
	int data;
	node* left;
	node* right;
};

node* create_node(int data) {
	node* new_node = new node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void insert_node(node* root, int data) {
	node* tmp = root;
	while (true) {
		if (data < tmp->data) {
			if (tmp->left == NULL) {
				tmp->left = create_node(data);
				break;
			} else {
				tmp = tmp->left;
			}
		} else {
			if (tmp->right == NULL) {
				tmp->right = create_node(data);
				break;
			} else {
				tmp = tmp->right;
			}
		}
	}
}

void postorder(node* curr_node) {
	if (curr_node == NULL) return ;
	postorder(curr_node->left);
	postorder(curr_node->right);
	cout << curr_node->data << endl;
}

int main() {
	// FASTIO;
	int n; cin >> n;
	node* root = create_node(n);
	postorder(root);
	while (true) {
		cin >> n;
		insert_node(root, n);
		postorder(root);
	}
}
