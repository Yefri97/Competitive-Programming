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

int cnt[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k; cin >> k;
	string s; cin >> s;
	int acc = 0;
	fori(i, 0, s.size()) {
		int c = s[i]-'0';
		cnt[c]++;
		acc += c;
	}
	int ans = 0, curr = 0;
	while (acc < k) {
		while (cnt[curr] == 0) curr++;
		acc += 9 - curr;
		cnt[curr]--;
		ans++;
	}
	cout << ans << endl;
	return 0;
}