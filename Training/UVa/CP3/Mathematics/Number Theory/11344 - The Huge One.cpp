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

bool check(string n, int m) {
	int k = 0;
	fori(i, 0, (int)n.size())
		k = (k * 10 + (n[i] - '0')) % m;
	return k == 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string n; cin >> n;
		int k, ans = 1; cin >> k;
		while (k--) {
			int x; cin >> x;
			ans &= check(n, x);
		}
		cout << n << " - " << (ans ? "Wonderful" : "Simple") << "." << endl;
	}
	return 0;
}