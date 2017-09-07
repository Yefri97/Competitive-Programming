#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 26;

int W[mxn + 10], in[mxn + 10], g[mxn + 10][mxn + 10], memo[mxn + 10];

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int nxtInt() {
	string n; getline(cin, n);
	return atoi(n.c_str());
}

int longestPath(int u) {
	if (memo[u] != -1) return memo[u];
	int ans = 0;
	fori(i, 0, mxn)
		if (g[u][i] == 1)
			ans = max(ans, longestPath(i));
	return memo[u] = ans + W[u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = nxtInt();
	string b; getline(cin, b);
	while (t--) {
		memset(in, 0, sizeof in);
		memset(g, 0, sizeof g);
		memset(W, 0, sizeof W);
		string line;
		while (getline(cin, line) && line.size()) {
			vector<string> input = splitLine(line);
			int id = input[0][0] - 'A';
			W[id] = atoi(input[1].c_str());
			if (input.size() == 3) {
				string s = input[2];
				fori(i, 0, s.size()) {
					int c = s[i] - 'A';
					g[c][id] = 1;
					in[id]++;
				}
			}
		}
		memset(memo, -1, sizeof memo);
		int ans = 0;
		fori(i, 0, mxn)
			if (in[i] == 0)
				ans = max(ans, longestPath(i));
		cout << ans << endl;
		if (t) cout << endl;
	}
	return 0;
}