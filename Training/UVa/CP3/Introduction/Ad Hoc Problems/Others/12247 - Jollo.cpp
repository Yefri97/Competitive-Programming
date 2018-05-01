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

bool check(vi a, vi b, int x) {
	b[2] = x;
	sort(b.begin(), b.end());
	return ((b[1] > a[2] && b[2] > a[2]) || (b[0] > a[1]));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi a(3), b(3);
	while (cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] && a[0]) {
		sort(a.begin(), a.end());
		int ans = 1;
		while (ans < 53) {
			if (find(a.begin(), a.end(), ans) == a.end() && find(b.begin(), b.end(), ans) == b.end())
				if (check(a, b, ans)) break;
			ans++;
		}
		if (ans == 53)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}