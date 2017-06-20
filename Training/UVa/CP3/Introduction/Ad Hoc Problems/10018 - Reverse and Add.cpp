// Palindrome
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

bool ispalindrome(string s) {
	fori(i, 0, s.size() / 2) {
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int result = 0;
		ll n; cin >> n;
		while (!ispalindrome(to_string(n))) {
			string s = to_string(n);
			reverse(s.begin(), s.end());
			ll x = atol(s.c_str());
			n += x;
			result++;
		}
		cout << result << " " << n << endl;
	}
	return 0;
}