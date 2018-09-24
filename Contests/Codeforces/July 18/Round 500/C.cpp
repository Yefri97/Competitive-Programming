#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<ll> a(2 * n);
	fori(i, 0, 2 * n)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll area = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	fori(i, 1, n)
		area = min(area, (a[i + n - 1] - a[i]) * (a[2 * n - 1] - a[0]));
	cout << area << endl;
	return 0;
}
