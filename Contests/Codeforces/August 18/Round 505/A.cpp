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
	int n; cin >> n;
	string s; cin >> s;
	vi f(26);
	for (char c : s)
		f[c - 'a']++;
	int cnt = 0;
	fori(i, 0, 26)
		cnt += (f[i] == 1);
	cout << (n > 1 && cnt == n ? "No" : "Yes") << endl;
	return 0;
}
