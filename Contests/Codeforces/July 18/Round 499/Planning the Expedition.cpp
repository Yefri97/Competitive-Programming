#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 110;

int freq[MX];

int can(int k, int n) {
	int c = 0;
	fori(i, 1, 101)
		c += freq[i] / k;
	return c >= n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, m) {
		int x; cin >> x;
		freq[x]++;
	}
	int lo = 0, hi = oo;
	while (hi - lo > 1) {
		int mi = (hi + lo) / 2;
		if (can(mi, n))
			lo = mi;
		else
			hi = mi;
	}
	cout << lo << endl;
	return 0;
}