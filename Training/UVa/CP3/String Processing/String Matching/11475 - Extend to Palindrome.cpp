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

const int oo = 1e9;

int kmp(string T, string P) {
	int n = T.size(), m = P.size();
	vector<int> b(m + 1); b[0] = -1;
	// Preprocess P
	int i = 0, j = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
	// Search T
	i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
	}
	return j;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (cin >> line) {
		string liner = line; reverse(liner.begin(), liner.end());
		int k = kmp(line, liner), n = line.size();
		string ans = line;
		ans += liner.substr(k, n - k);
		cout << ans << endl;
	}
	return 0;
}