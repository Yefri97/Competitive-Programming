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

vector<ll> lucky;

bool check(string s) {
	vi v(2);
	fori(i, 0, s.size())
		v[(s[i] == '7')]++;
	return (v[0] == v[1]);
}

void gen(int id, string s) {
	if (id == 0) {
		if (check(s)) lucky.push_back(atoi(s.c_str()));
		return;
	}
	gen(id - 1, s + "4");
	gen(id - 1, s + "7");
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(k, 1, 5)
		gen(2 * k, "");
	lucky.push_back(4444477777);
	int n; cin >> n;
	cout << *(lower_bound(lucky.begin(), lucky.end(), n)) << endl;
	return 0;
}