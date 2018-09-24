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
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	vi ans;
	fori(i, 0, n - 1) {
		if (a[i] >= a[i + 1])
			ans.push_back(a[i]);
	}
	ans.push_back(a[n - 1]);
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}
