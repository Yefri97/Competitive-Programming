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

int kmp(string P) {
	int m = P.size();
	vi b(m + 1); b[0] = -1;
	// Preprocess P
	int i = 0, j = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
	return b[m];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (cin >> line && line != ".") {
		int k = kmp(line), m = line.size();
		int ans = m / (m - k);
		cout << ans << endl;
	}
	return 0;
}