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
	int tc; cin >> tc;
	fori(t, 0, tc) {
		cout << "Case #" << t + 1 << ": ";
		string s; cin >> s;
		int n = s.size();
		int a = -1, b = -1;
		fori(i, 1, n) {
			int j = 0;
			while (i + j < n && s[j] == s[i + j]) j++;
			if (j != 0 && i + j < n) a = i, b = j;
		}
		if (a == -1) {
			cout << "Impossible" << endl;
		} else {
			fori(i, 0, a + b) cout << s[i];
			fori(i, b, n) cout << s[i];
			cout << endl;
		}
	}
	return 0;
}
