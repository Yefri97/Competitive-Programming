/*
ID: yefri.g1
PROG: crypt1
LANG: C++
*/
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int check(vi& v, int x) {
	while (x) {
		if (find(v.begin(), v.end(), x % 10) == v.end()) return 0;
		x /= 10;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin ("crypt1.in");
  ofstream fout ("crypt1.out");
	int n; fin >> n;
	vi v(n);
	fori(i, 0, n)
		fin >> v[i];
	int ans = 0;
	fori(a, 0, n)
		fori(b, 0, n)
			fori(c, 0, n)
				fori(d, 0, n)
					fori(e, 0, n) {
						int y = 100 * v[a] + 10 * v[b] + v[c];
						int x = 10 * v[d] + v[e];
						int ok = 1;
						ok &= y * v[e] < 1000 && check(v, y * v[e]);
						ok &= y * v[d] < 1000 && check(v, y * v[d]);
						ok &= y * x < 10000 && check(v, y * x);
						ans += ok;
					}
	fout << ans << endl;
	return 0;
}