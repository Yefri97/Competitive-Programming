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

const int oo = 1e9;

int n, target;
string b;

double solver(int id, int curr) {
	if (id == n) return curr == target;
	if (b[id] != '?') return solver(id + 1, curr + (b[id] == '+' ? 1 : -1));
	return 0.5 * solver(id + 1, curr + 1) + 0.5 * solver(id + 1, curr - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a; cin >> a >> b;
	n = a.size();
	target = 0;
	fori(i, 0, n)
		target += (a[i] == '+' ? 1 : -1);
	double ans = solver(0, 0);
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}