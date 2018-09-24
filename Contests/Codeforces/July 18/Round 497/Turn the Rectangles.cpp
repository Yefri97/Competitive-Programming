#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

int w[MN], h[MN];

int solve(int n) {
	int curr = max(w[0], h[0]);
	fori(i, 1, n) {
		if (w[i] <= curr && h[i] <= curr) {
			curr = max(w[i], h[i]);
		} else if (w[i] > curr && h[i] > curr) {
			return 0;
		} else {
			curr = min(w[i], h[i]);
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> w[i] >> h[i];
	int ans = solve(n);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
