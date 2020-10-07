#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

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
	int ans = 0;
	i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (j == m) {
			ans++;
			j = b[j];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	string s; cin >> s;
	string p; cin >> p;
	cout << kmp(s, p) << endl;
	return 0;
}
