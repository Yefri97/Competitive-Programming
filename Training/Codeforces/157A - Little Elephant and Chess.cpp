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

bool check(string s) {
	fori(i, 1, s.size())
		if (s[i-1] == s[i])
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string row;
	bool ans = true;
	while (cin >> row)
		ans &= check(row);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}