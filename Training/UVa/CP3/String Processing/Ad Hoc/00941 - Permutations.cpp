#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<ll> fact(21);
	fact[0] = 1;
	fori(i, 1, 21)
		fact[i] = fact[i - 1] * i;
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		ll n; cin >> n;
		int m = s.size();
		vi freq(26);
		fori(i, 0, m)
			freq[s[i] - 'a']++;
		string ans;
		ll x = fact[m];
		fori(i, 0, 26) x /= fact[freq[i]];
		fori(i, 0, m) {
			fori(j, 0, 26) {
				if (n < (x * freq[j]) / (m - i)) {
					x = (x * freq[j]) / (m - i);
					freq[j]--;
					ans.push_back(j + 'a');
					break;
				} else {
					n -= (x * freq[j]) / (m - i);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}