#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 2010;

int a[MN];

int cmp(int i, int j) { return a[i] > a[j]; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n)
		cin >> a[i];
	vi id(n);
	fori(i, 0, n)
		id[i] = i;
	sort(id.begin(), id.end(), cmp);
	sort(id.begin(), id.begin() + k);
	vi ans(k + 1);
	int sum = 0;
	ans[0] = -1;
	fori(i, 1, k) {
		ans[i] = id[i - 1];
		sum += a[id[i - 1]];
	}
	ans[k] = n - 1;
	sum += a[id[k - 1]];
	cout << sum << endl;
	fori(i, 1, k + 1)
		cout << ans[i] - ans[i - 1] << " ";
	cout << endl;
	return 0;
}
