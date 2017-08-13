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

string process(string s) {
	while (s.back() == '0') s.pop_back();
	fori(i, 0, s.size()/2) swap(s[i], s[s.size() - i - 1]);
	return s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string a, b; cin >> a >> b;
		string sa = process(a), sb = process(b), ans;
		int n = max(sa.size(), sb.size()), carry = 0;
		fori(i, 0, n) {
			int ca = (i < sa.size() ? sa[sa.size() - i - 1]-'0' : 0);
			int cb = (i < sb.size() ? sb[sb.size() - i - 1]-'0' : 0);
			int x = ca + cb + carry;
			ans.push_back((char)((x % 10)+'0'));
			carry = x / 10;
		}
		if (carry) ans.push_back((char)(carry+'0'));
		fori(i, 0, ans.size()/2) swap(ans[i], ans[ans.size() - i - 1]); 
		ans = process(ans);
		cout << ans << endl;
	}
	return 0;
}