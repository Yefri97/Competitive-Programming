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

const int oo = 1e9, mxn = 300010;

ll k, c;
ll A[mxn];
int its[mxn];
vector<ll> sets[70];

int solver(int idk, ll x) {
	/*debug(idk);
	debug(its[idk]);
	debug(x);
	cout << endl;*/
	if (idk == k) return 1;
	while (its[idk] < sets[idk].size() && sets[idk][its[idk]] < x) its[idk]++;
	if (its[idk] == sets[idk].size()) return 0;
	its[idk]++;
	return solver(idk + 1, c * sets[idk][its[idk]-1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n >> k >> c;
		fori(i, 0, n)
			cin >> A[i];
		sort(A, A + n);
		fori(i, 0, k) sets[i].clear();
		for (int i = 0, it = 0; it < n; i++)
			for (int j = 0; it < n && j < (n + k - 1) / k; j++)
				sets[i].push_back(A[it++]);
		/*fori(i, 0, sets.size()) {
			fori(j, 0, sets[i].size())
				cout << sets[i][j] << " ";
			cout << endl;
		}*/
		int ans = 0;
		fori(i, 0, k) its[i] = 0;
		while (its[0] < sets[0].size()) {
			ans += solver(1, c * sets[0][its[0]]);
			its[0]++;
		}
		cout << ans << endl;
	}
	return 0;
}