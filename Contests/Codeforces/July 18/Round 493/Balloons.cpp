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
	if (n == 1 || n == 2 && a[0] == a[1]) {
		cout << -1 << endl;
	} else {
		cout << 1 << endl;
		cout << (min_element(a.begin(), a.end()) - a.begin()) + 1 << endl;
	}
	return 0;
}
