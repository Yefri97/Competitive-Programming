#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 8000;

int n;
int A[mxn + 10], memo[mxn + 10][mxn + 10];
unordered_map<int, vi> ocur;
unordered_map<int, int> mapper;

int gauss(int x) { return (x * (x + 1)) >> 1; }

int solver(int x, int y) {
	vi ocurx = ocur[x], ocury = ocur[y];
	if (ocurx.size() == 0) x = -1;
	if (ocury.size() == 0) y = -1;
	if (x == y) return gauss(n);
	int idx = mapper[x], idy = mapper[y];
	if (memo[idx][idy] != -1) return memo[idx][idy];
	ocurx.push_back(oo);
	ocury.push_back(oo);
	vi merge;
	int i = 0, j = 0;
	while (i < ocurx.size() - 1 || j < ocury.size() - 1) {
		if (ocurx[i] < ocury[j]) {
			merge.push_back(ocurx[i]);
			i++;
		} else {
			merge.push_back(ocury[j]);
			j++;
		}
	}
	merge.push_back(n);
	unordered_map<int, int> v;
	int cntx = 0, cnty = 0;
	v[0] += merge[0] + 1;
	fori(i, 0, merge.size() - 1) {
		if (A[merge[i]] == x) cntx++;
		else cnty++;
		v[cntx - cnty] += merge[i + 1] - merge[i];
	}
	int ans = 0;
	for (unordered_map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		ans += gauss((it->second) - 1);
	return memo[idx][idy] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(memo, -1, sizeof memo);
	int q; cin >> n >> q;
	int id = 0;
	fori(i, 0, n) {
		int x; cin >> x;
		A[i] = x;
		ocur[x].push_back(i);
		if (mapper[x] == 0) mapper[x] = ++id;
	}
	while (q--) {
		int x, y; cin >> x >> y;
		int ans = solver(x, y);
		cout << ans << endl;
	}
	return 0;
}