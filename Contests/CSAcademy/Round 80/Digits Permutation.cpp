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
	string a; cin >> a;
	ll b; cin >> b;
	sort(a.begin(), a.end());
	ll ans = -1;
	do {
		ll c = stol(a);
		if (a[0] != '0' && c <= b)
			ans = max(ans, c);
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << endl;
	return 0;
}
