#include <bits/stdc++.h>

using namespace std;

int main(int argv, char* argc[]) {
	string line;
	if (argv == 3) {
		// make file
		if (strcmp(argc[2], "m") == 0) {
			ofstream file;
			file.open(string(argc[1]) + ".cpp");
			// ofstream file(string(argc[1]) + ".cpp");
			if (file.is_open()) {
				file << "#include <bits/stdc++.h>" << endl;
				file << "#define endl \"\\n\"" << endl;
				file << "#define INF 1e9" << endl;
				file << "#define dir4 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}" << endl;
				file << "#define dir8 {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}" << endl;
				file << "#define board_condition(row, col, n, m) (row >= 0 && row < n && col >= 0 && col < m)" << endl;
				file << "#define FASTIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)" << endl;
				file << "#define F first" << endl;
				file << "#define S second" << endl;
				file << "#define PB push_back" << endl;
				file << "#define REP(i, a, b) for (int i = a; i < b; i++)" << endl;
				file << "#define SORT(x) sort(x.begin(), x.end())" << endl;
				file << "#define REV(x) reverse(x.begin(), x.end())" << endl;
				file << "#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())" << endl;
				file << "#define VINPUT(v, n) REP(i, 0, n) { int tmp; cin >> tmp; v.PB(tmp); }" << endl;
				file << "#define VOUTPUT(v) REP(i, 0, v.size()) { cout << v[i] << \" \"; } cout << endl" << endl;
				file << "#define V2DINPUT(v, n, m) REP(i, 0, n) { vi tmpv; REP(j, 0, m) { int tmp; cin >> tmp; tmpv.PB(tmp); } v.PB(tmpv); }" << endl;
				file << "#define V2DOUTPUT(v) REP(i, 0, v.size()) { REP(j, 0, v[i].size()) { cout << v[i][j] << \" \"; } cout << endl; } cout << endl" << endl;
				file << "#define WATCH(x) cout << #x << \" : \" << x << endl" << endl;
				file << "#define DEBUG(x) cout << \"DB - \" << x << endl" << endl;
				file << "#define PRINT(x) cout <<  x << endl" << endl;
				file << "#define NVOUTPUT(x)" << endl;
				file << "#define NV2DOUTPUT(x)" << endl;
				file << "#define NWATCH(x)" << endl;
				file << "#define NDEBUG(x)" << endl;
				file << "#define NPRINT(x)" << endl;
				file << endl;
				file << "using namespace std;" << endl;
				file << endl;
				file << "typedef long long ll;" << endl;
				file << "typedef vector<int> vi;" << endl;
				file << "typedef vector<vi> vvi;" << endl;
				file << "typedef vector<string> vs;" << endl;
				file << "typedef pair<int, int> pi;" << endl;
				file << "struct point {" << endl;
				file << "\tint x, y;" << endl;
				file << "};" << endl;
				file << endl;
				file << "int main() {" << endl;
				file << "\tFASTIO;" << endl;
				file << "}" << endl;
				file.close();
				cout << "Make file done" << endl;
			} else {
				cout << "error" << endl;
				return 1;
			}
		} 
		// compile file
		else if (strcmp(argc[2], "c") == 0) {
			string command = "g++ " + string(argc[1]) + ".cpp -o iwtkmn";
			system(command.c_str());
			cout << "Compile done" << endl;
		}
	} else {
		cout << "Please input 3 argument" << endl;
	}
}