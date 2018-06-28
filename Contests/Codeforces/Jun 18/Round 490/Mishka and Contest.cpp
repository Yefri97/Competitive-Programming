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
	int n, k; cin >> n >> k;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	int i = 0;
	while (i < n && v[i] <= k) i++;
	int j = n - 1;
	while (j > i && v[j] <= k) j--;
	int ans = i + (n - 1 - j);
	cout << ans << endl;
	return 0;
}
