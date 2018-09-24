#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int l = 0;
	fori(i, 1, n)
		if (s.substr(n - i, i) == s.substr(0, i))
			l = i;
	cout << s;
	fori(i, 0, k - 1)
		cout << s.substr(l, n - l);
	cout << endl;
	return 0;
}
