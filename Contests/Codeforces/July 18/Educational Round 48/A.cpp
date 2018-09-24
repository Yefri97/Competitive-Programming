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
	int n, m; cin >> n >> m;
	vector<ll> a(n);
	fori(i, 0, n)
		cin >> a[i];
	fori(i, 1, n)
		a[i] += a[i - 1];
	cout << a[0] / m;
	fori(i, 1, n)
		cout << " " << a[i] / m - a[i - 1] / m;
	cout << endl;
	return 0;
}
