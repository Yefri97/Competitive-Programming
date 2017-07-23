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

ii solver(int a, int b, int prev) {
	ii ans;
	vi v(2);
	v[0] = a, v[1] = b;
	v[prev]--;
	fori(i, 1, a + b) {
		int curr;
		if (i % 2 == 0)
			curr = (v[prev] ? prev : 1 - prev);
		else 
			curr = (v[1 - prev] ? 1 - prev : prev);
		v[curr]--;
		if (curr == prev) ans.first++;
		else ans.second++;
		prev = curr;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b; cin >> a >> b;
	ii x = solver(a, b, 0);
	ii y = solver(a, b, 1);
	if (x.first > y.first)
		cout << x.first << " " << x.second << endl;
	else
		cout << y.first << " " << y.second << endl;
	return 0;
}