#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 100010;

int freq[2][MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	int cnt = 0;
	fori(i, 0, n) {
		int x = a[n - i - 1];
		if (freq[1][x] == 0)
			cnt++;
		freq[1][x]++;
	}
	ll ans = 0;
	fori(i, 0, n) {
		int x = a[i];
		if (freq[1][x] == 1)
			cnt--;
		freq[1][x]--;
		if (freq[0][x] == 0)
			ans += cnt;
		freq[0][x]++;
	}
	cout << ans << endl;
	return 0;
}
