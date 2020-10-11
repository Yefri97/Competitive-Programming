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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i) continue;
			ans++;
			if (i * i != n) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

/* Sieve modified */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	for (int i = 1; i < MN; i++)
		for (int j = i; j < MN; j += i)
			divs[j]++;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << divs[n] << endl;
	}
	return 0;
}