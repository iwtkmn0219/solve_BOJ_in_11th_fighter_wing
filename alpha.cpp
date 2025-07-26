#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main(int argv, char* argc[]) {
	if (argv == 2) {
		// compile
		string problem_name = argc[1];
		string command = "g++ " + problem_name + ".cpp -o " + problem_name;
		system(command.c_str());
	} else if (argv == 3) {
		string problem_name = argc[1];
		if (strcmp(argc[2], "m") == 0) {
			// make file
			string command = "touch " + problem_name + ".cpp";
			cout << command;
			system(command.c_str());
			command = "echo off\necho \"#include <bits/stdc++.h>\n#define INF 1e9\n#define F first\n#define S second\n#define PB push_back\n#define MP make_pair\n#define REP(i, a, b) for (int i = a; i < b; i++)\n#define REPR(i, a, b) for (int i = a; i >= b; i--)\n#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)\n#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }\n#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << " "; }\n#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }\n#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << " "; } cout << endl; }\n\nusing namespace std;\n\ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef vector<vi> vvi;\ntypedef vector<string> vs;\ntypedef pair<int, int> pi;\n\nint main() \{\n\tFASTIO;\n\}\" > " + problem_name + ".cpp";
			system(command.c_str());
			cout << command;
		}
	}
}