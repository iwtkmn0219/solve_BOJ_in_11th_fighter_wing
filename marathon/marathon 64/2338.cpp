#include <bits/stdc++.h>
#define endl "\n"
#define INF 1e9
#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}
#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define F first
#define S second
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
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
struct point {
	int x, y;
};

string remove_zero(string s) {
	if (s.size() == 1) return s;
	int idx = -1;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == '0') idx = i;
		else break;
	}
	return s.substr(idx + 1);
}

string bigger_add(string a, string b) {
	string result = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() < b.size())
		swap(a, b);
	for (int i = b.size(); i < a.size(); i++) {
		b += '0';
	}

	int u = 0;;
	for (int i = 0; i < a.size(); i++) {
		int x = a[i] - '0', y = b[i] - '0';
		int s = x + y + u;
		u = s / 10; 
		s %= 10;
		result += s + '0';
	}

	if (u) result += '1';
	reverse(result.begin(), result.end());
	result = remove_zero(result);
	return result;
}

bool aisbig(string a, string b) {
	if (a.size() != b.size()) return a.size() > b.size();
	for (int i = 0; i < a.size(); i--) {
		if (a[i] == b[i]) continue;
		return a[i] > b[i];
	}
	return true;
}

string bigger_sub(string a, string b) {
	if (a == b) return "0";
	if (!aisbig(a, b)) swap(a, b);
	reverse(b.begin(), b.end());
	string result = "";

	for (int i = b.size(); i < a.size(); i++) {
		b += '0';
	}
	
	string nine_comp = "";
	for (int i = 0; i < b.size(); i++) {
		nine_comp += '0' + ('9' - b[i]);
	}
	reverse(nine_comp.begin(), nine_comp.end());
	string tmp = bigger_add(nine_comp, a);
	if (tmp.size() != b.size()) {
		tmp = bigger_add(tmp, "1");
		result = tmp.substr(1);
	} else {
		result = tmp;
	}
	result = remove_zero(result);
	return result;
}

string bigger_mul(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() < b.size())
		swap(a, b);
	for (int i = b.size(); i < a.size(); i++) {
		b += '0';
	}

	string result = "";
	for (int i = 0; i < b.size(); i++) {
		string tmp_result = "";
		int u = 0;
		for (int k = 0; k < i; k++) {
			tmp_result += '0';
		}
		for (int j = 0; j < a.size(); j++) {
			int x = a[j] - '0';
			int y = b[i] - '0';
			int s = x * y + u;
			u = s / 10;
			s %= 10;
			tmp_result += s + '0';
		}
		if (u) tmp_result += u + '0';
		reverse(tmp_result.begin(), tmp_result.end());
		tmp_result = remove_zero(tmp_result);
		NWATCH(tmp_result);
		result = bigger_add(result, tmp_result);
		NWATCH(result);
	}
	result = remove_zero(result);
	return result;
}

int main() {
	FASTIO;
	string a, b; cin >> a >> b;
	if (a == "0") {
		cout << b << endl;
		cout << ((b[0] == '-') ? b.substr(1) : b) << endl;
		cout << 0 << endl;
		return 0;
	}

	if (b == "0") {
		cout << a << endl;
		cout << a << endl;
		cout << 0 << endl;
		return 0;
	}

	
	
	// plus
	if (a[0] == '-' && b[0] == '-') {
		string tmpa = a.substr(1), tmpb = b.substr(1);
		cout << "-" << bigger_add(tmpa, tmpb) << endl;
	} else if (a[0] != '-' && b[0] != '-') {
		cout << bigger_add(a, b) << endl;
	} else {
		if (a[0] == '-') {
			string tmpa = a.substr(1);
			if (tmpa == b) {
				cout << 0 <<  endl;
			} else {
				cout << (aisbig(tmpa, b) ? "-" : "") << bigger_sub(tmpa, b) << endl;
			}
		} else {
			string tmpb = b.substr(1);
			cout << (aisbig(a, tmpb) ? "" : "-") << bigger_sub(a, tmpb) << endl;
		}
	}
	// minus
	if (a[0] != '-' && b[0] == '-') {
		string tmpb = b.substr(1);
		cout << bigger_add(a, tmpb) << endl;
	} else if (a[0] == '-' && b[0] != '-') {
		string tmpa = a.substr(1);
		cout << "-" << bigger_add(tmpa, b) << endl;
	} else {
		if (a[0] == '-') {
			string tmpa = a.substr(1), tmpb = b.substr(1);
			if (tmpa == tmpb) {
				cout << 0 << endl;
			} else {
				cout << (aisbig(tmpa, tmpb) ? "-" : "") << bigger_sub(tmpa, tmpb) << endl;
			}
		} else {
			cout << (aisbig(a, b) ? "" : "-") << bigger_sub(a, b) << endl;
		}
	}

	if (a[0] == '-' && b[0] == '-') {
		a = a.substr(1);
		b = b.substr(1);
		cout << bigger_mul(a, b);
	} else if (a[0] != '-' && b[0] != '-') {
		cout << bigger_mul(a, b);
	} else {
		if (a[0] == '-') {
			a = a.substr(1);
			cout << "-" << bigger_mul(a, b);
		} else {
			b = b.substr(1);
			cout << "-" << bigger_mul(a, b);
		}
	}
}
