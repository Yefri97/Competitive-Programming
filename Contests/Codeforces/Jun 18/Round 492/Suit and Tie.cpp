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
	vi v(2 * n);
	fori(i, 0, 2 * n)
		cin >> v[i];
	int ans = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		int j = i + 1;
		while (v[j] != v[i]) j++;
		while (j > i + 1) {
			swap(v[j], v[j - 1]);
			ans++;
			j--;
		}
	}
	cout << ans << endl;
	return 0;
}
