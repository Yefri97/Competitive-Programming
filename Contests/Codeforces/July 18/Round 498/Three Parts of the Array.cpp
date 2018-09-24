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
	int n; cin >> n;
	vector<ll> a(n + 1), b(n + 1);
	fori(i, 1, n + 1) {
		int x; cin >> x;
		a[i] = x;
		b[n - i + 1] = x;
	}
	fori(i, 1, n + 1) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	int l = n, r = n;
	while (l >= 0) {
		while (b[r] > a[l])
			r--;
		if (r + l <= n && b[r] == a[l]) break;
		l--;
	}
	cout << a[l] << endl;
	return 0;
}
