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
	vi a(n), b(m);
	fori(i, 0, n)
		cin >> a[i];
	fori(i, 0, m)
		cin >> b[i];
	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (b[j] >= a[i]) {
			j++;
			ans++;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}
