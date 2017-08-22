#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi v1, v2;
	int n; cin >> n;
	fori(i, 0, n) {
		char c; cin >> c;
		v1.push_back(c - '0');
	}
	fori(i, 0, n) {
		char c; cin >> c;
		v2.push_back(c - '0');
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	bool a = true, b = true;
	fori(i, 0, n)
		a &= (v1[i] < v2[i]);
	fori(i, 0, n)
		b &= (v1[i] > v2[i]);
	cout << (a || b ? "YES" : "NO") << endl;
	return 0;
}