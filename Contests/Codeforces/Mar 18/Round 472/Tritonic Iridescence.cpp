#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 110;

int solve(string s) {
	int n = s.size();
	fori(i, 0, n - 1) if (s[i] != '?' && s[i] == s[i + 1]) return 0;
	if (s[0] == '?' || s[n - 1] == '?') return 1;
	fori(i, 1, n - 1) if (s[i] == '?')
		if (s[i - 1] == '?' || s[i + 1] == '?' || s[i - 1] == s[i + 1])
			return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int ans = solve(s);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
