#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vi a(m);
	fori(i, 0, m)
		cin >> a[i];
	fori(i, 1, m)
		a[i] += a[i - 1];
	int p = upper_bound(a.begin(), a.end(), n / 2) - a.begin();
	if (2 * a[p - 1] == n)
		cout << -1 << endl;
	else
		cout << p + 1 << endl;
	return 0;
}
