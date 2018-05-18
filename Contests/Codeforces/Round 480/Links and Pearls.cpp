#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	vi v(2);
	for (char c : s)
		v[(c == 'o')]++;
	int ans = 0;
	if (v[1] == 0 || v[0] % v[1] == 0) ans = 1;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
