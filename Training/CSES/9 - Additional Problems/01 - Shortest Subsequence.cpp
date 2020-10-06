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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	string adn = "ACGT";
	string s; cin >> s;
	int it = 0;
	while (true) {
		int ri = -1;
		for (char c : adn) {
			int p = it;
			while (p < SZ(s) && s[p] != c) p++;
			if (p == SZ(s)) {
				cout << c << endl;
				return 0;
			}
			ri = max(ri, p);
		}
		cout << s[ri];
		it = ri + 1;
	}
	return 0;
}
