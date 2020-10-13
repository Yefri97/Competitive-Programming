#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	ll sum = (1LL * n * (n + 1)) / 2;
	if (sum % 2) {
		cout << "NO" << endl;
		return 0;
	}
	vi a, b;
	int le = 1, ri = n;
	if (n % 2) {
		a.pb(le); le++;
		b.pb(ri); ri--;
		a.pb(ri); ri--;
	}
	while (ri > le) {
		a.pb(le); le++;
		a.pb(ri); ri--;
		b.pb(le); le++;
		b.pb(ri); ri--;
	}
	cout << "YES" << endl;
	cout << SZ(a) << endl;
	for (int x : a)
		cout << x << " ";
	cout << endl;
	cout << SZ(b) << endl;
	for (int x : b)
		cout << x << " ";
	cout << endl;
	return 0;
}
