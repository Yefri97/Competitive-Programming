#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 25;

int n;
int order[mxn];
char vars[mxn];
bool ans, g[mxn][mxn];

bool can(int u, int id) {
	fori(i, 0, id)
		if (g[u][order[i]])
			return false;
	return true;
}

void backtracking(int id) {
	if (id == n) { 
		ans = true;
		cout << vars[order[0]];
		fori(i, 1, n)
			cout << " " << vars[order[i]];
		cout << endl;
		return;
	}
	fori(u, 0, n) {
		if (can(u, id)) {
			order[id] = u;
			backtracking(id + 1);
		}
	}
}

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int nextInt() {
	string n; getline(cin, n);
	return atoi(n.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = nextInt();
	while (t--) {
		string b; getline(cin, b);
		string strvars; getline(cin, strvars);
		string strcons; getline(cin, strcons);
		vector<string> listvars = splitLine(strvars), listcons = splitLine(strcons);
		sort(listvars.begin(), listvars.end());
		n = listvars.size();
		map<char, int> mapper;
		fori(i, 0, n) {
			vars[i] = listvars[i][0];
			mapper[vars[i]] = i;
		}
		memset(g, false, sizeof g);
		fori(i, 0, listcons.size()) {
			int a = mapper[listcons[i][0]], b = mapper[listcons[i][2]];
			g[a][b] = true;
		}
		fori(i, 0, n) g[i][i] = true;
		ans = false;
		backtracking(0);
		if (!ans) cout << "NO" << endl;
		if (t) cout << endl;
	}
	return 0;
}