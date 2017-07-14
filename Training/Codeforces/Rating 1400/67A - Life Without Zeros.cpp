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

int convert(int n) {
	int ans = 0, p = 1;
	while (n) {
		if (n % 10) {
			ans += (n % 10) * p;
			p *= 10;
		}
		n /= 10;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b; cin >> a >> b;
	int c = a + b;
	int na = convert(a), nb = convert(b), nc = convert(c);
	if (na + nb == nc) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}