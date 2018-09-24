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
	string a; cin >> a;
	string b; cin >> b;
	int ans = 0;
	fori(i, 0, n - 1) {
		if (a[i] != a[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]) {
			swap(a[i], a[i + 1]);
			ans++;
		}
	}
	fori(i, 0, n)
		if (a[i] != b[i])
			ans++;
	cout << ans << endl;
	return 0;
}
