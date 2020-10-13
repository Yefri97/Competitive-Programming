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
	int n, m; cin >> n >> m;
	multiset<int> dict;
	fori(i, 0, n) {
		int x; cin >> x;
		dict.insert(x);
	}
	fori(i, 0, m) {
		int x; cin >> x;
		auto it = dict.upper_bound(x);
		if (it == dict.begin()) {
			cout << -1 << endl;
		} else {
			it--;
			cout << *it << endl;
			dict.erase(it);
		}
	}
	return 0;
}
