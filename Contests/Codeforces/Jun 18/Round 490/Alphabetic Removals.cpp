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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vi del(n);
	fori(i, 0, 26) {
		fori(j, 0, n) if (k > 0 && s[j] == i + 'a') {
			del[j] = 1;
			k--;
		}
		if (k == 0) break;
	}
	fori(i, 0, n)
		if (!del[i])
			cout << s[i];
	cout << endl;
	return 0;
}
