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

bool check(vi a, vi b) {
	fori(i, 0, 3) {
		bool ok = true;
		fori(j, 0, 3) {
			ii x = ii(i == 0 ? a[1] : a[0], i == 2 ? a[1] : a[2]);
			ii y = ii(j == 0 ? b[1] : b[0], j == 2 ? b[1] : b[2]);
			ok &= (x.first < y.first && x.second < y.second) ||
						((x.first < y.first || x.second < y.second) && a[i] < a[j]);
		}
		if (ok) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi a(3), taken(7);
	fori(i, 0, 3) {
		int x; cin >> x; x--;
		a[i] = x;
		taken[x] = 1;
	}
	sort(a.begin(), a.end());
	bool ans = true;
	fori(i, 0, 7) if (!taken[i])
		fori(j, i + 1, 7) if (!taken[j])
			fori(k, j + 1, 7) if (!taken[k])
				ans &= check(a, {i, j, k});
	cout << (ans ? "S" : "N") << endl;
	return 0;
}