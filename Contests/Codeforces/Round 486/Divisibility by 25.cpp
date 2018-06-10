#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int doit(string s, char a, char b) {
	int n = s.size(), ans = 0;
	if (n == 1) return oo;
	int d1 = n - 1;
	while (d1 >= 0 && s[d1] != b)
		d1--;
	if (d1 == -1) return oo;
	fori(i, d1, n - 1) {
		swap(s[i], s[i + 1]);
		ans++;
	}
	s[n - 1] = b;
	int d2 = n - 2;
	while (d2 >= 0 && s[d2] != a)
		d2--;
	if (d2 == -1) return oo;
	fori(i, d2, n - 2) {
		swap(s[i], s[i + 1]);
		ans++;
	}
	s[n - 2] = a;
	int d3 = 0;
	while (d3 < n && s[d3] == '0')
		d3++;
	ans += d3;
	return ans;
}

int solve(string s) {
	int ans = doit(s, '0', '0');
	ans = min(ans, doit(s, '2', '5'));
	ans = min(ans, doit(s, '5', '0'));
	ans = min(ans, doit(s, '7', '5'));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int ans = solve(s);
	cout << (ans < oo ? ans : -1) << endl;
	return 0;
}
