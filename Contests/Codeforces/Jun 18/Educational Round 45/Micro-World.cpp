#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 2000010;

int A[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n) {
		int x; cin >> x;
		A[x]++;
	}
	int w = 0;
	fori(i, 0, k)
		w += A[i];
	int ans = n;
	fori(i, 0, MX - k) {
		w += A[i + k];
		w -= A[i];
		if (w > 0)
			ans -= A[i];
	}
	cout << ans << endl;
	return 0;
}
